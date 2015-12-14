#include "def.h"
#include <stdio.h>
/**
 * Aloca dinamicamente memoria com base nos valores informados pelo usuario
 * @param  int linhas
 * @param  int colunas
 * @return Array<celula>
 */
celula** alocarInicializar(int linhas, int colunas){
    celula **celulas;
    int i, j;
    //alloc lines
    celulas = malloc(linhas * sizeof(celula)); 
    //alloc columns of lines
    for(i = 0; i < linhas; i++){
        celulas[i] = malloc(colunas * sizeof(celula)); 
    }
    //initializes
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            celulas[i][j].status = 0;
            celulas[i][j].x      = i;
            celulas[i][j].y      = j;
        }
    }
    return celulas;
}

/**
 * Recebe uma matriz de celulas e analisando celula por celula define quem vive na proxima geracao
 * @param  Array<celula> celulas
 * @param  int linhas
 * @param  int colunas
 * @return Array<celulas>
 */
celula** proximaGeracao(celula **celulas, int linhas, int colunas){
    celula **celulas2 = alocarInicializar(linhas, colunas);
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            int qtdVizinhosVivos = obterQtdVizinhosVivos(celulas, i, j, linhas, colunas);
            if(qtdVizinhosVivos == 3 || (celulas[i][j].status && qtdVizinhosVivos == 2)){
                celulas2[i][j].status =  1;
            }
        }
    }
    return celulas2;
}

/**
 * A partir das coordenadas da celula analisa seus vizinhos e retorna a quantidade de vizinhos vivos
 * @param  Array<celula> celulas
 * @param  int x
 * @param  int y
 * @param  int linhas
 * @param  int colunas
 * @return int qtdVizinhosVivos
 */
int obterQtdVizinhosVivos(celula **celulas, int x, int y, int lines, int columns){
    int qtdVizinhosVivos = 0;
    int cont 			 = 0;
    celula vizinhos[8];

    if(x != 0){
        vizinhos[cont++] = celulas[ x - 1 ] [ y ];
        if(y > 0){
            vizinhos[cont++] = celulas[ x - 1 ] [ y - 1 ];
        }
        if(y < (columns-1)){
            vizinhos[cont++] = celulas[ x - 1 ] [ y + 1 ];
        }
    }

    if(x < (lines-1)){
        vizinhos[cont++] = celulas[ x + 1 ] [ y ];
        if(y > 0){
            vizinhos[cont++] = celulas[ x + 1 ] [ y - 1 ];
        } 
        if(y < (columns-1)){
            vizinhos[cont++] = celulas[ x + 1 ] [ y + 1 ];
        }
    }

    if(y > 0){
        vizinhos[cont++] = celulas[ x ] [ y - 1 ];
    }

    if(y < (columns-1)){
        vizinhos[cont++] = celulas[ x ] [ y + 1 ];
    }

    int i;
    for(i = 0; i < cont; i++){
        if(vizinhos[i].status){
            qtdVizinhosVivos++;
        }
    }
    return qtdVizinhosVivos;
}

/**
*
*	Operacoes com arquivos
*
**/


/**
 * Carrega a matriz a partir de um arquivo binario
 * @param  Array<celula> celulas
 * @param  int    linhas
 * @param  int    colunas
 * @param  char[] local
 * @return Array<celula> 
 */
celula** carregarMatriz(int *linhas, int *colunas, char local[]){
    celula **celulas;
    FILE *f = fopen(local, "r");
    int i, j;
    int qtdItensCarregados = 0;

    //carrega a dimensao da matriz
    dimensao d;
    fread(&d, sizeof(dimensao), 1, f);
    *linhas  = d.linhas;
    *colunas = d.colunas; 

    //calcula a qtd de itens
    int qtdItens = d.linhas * d.colunas;

    //aloca e inicializa a matriz
    celulas = alocarInicializar(d.linhas, d.colunas);

    //carrega as  celulas
    for(i = 0; i < *linhas; i++){
        for(j = 0; j < *colunas; j++){
            qtdItensCarregados += fread(&celulas[i][j], sizeof(celula), 1, f);
        }
    }

    if(qtdItensCarregados != qtdItens) {
        printf("#> Erro ao carregar arquivo!");
        exit(0);
    }else {
        printf("#> Leitura de arquivo efetuada com sucesso!");
    }

    fclose(f);
    return celulas;
}

/**
 * Salva a matriz no disco como um arquivo binario
 * @param  Array<celula> celulas
 * @param  int    linhas
 * @param  int    colunas
 * @param  char[] local
 * @return void 
 */
void salvarMatriz(celula **celulas, int linhas, int colunas, char local[]){
    FILE *f = fopen(local, "w");
    int i, j;
    int qtdItensGravados = 0;
    int qtdItens = linhas * colunas;

    //salva a dimensao da matriz
    dimensao d;
    d.linhas  = linhas;
    d.colunas = colunas; 
    fwrite(&d, sizeof(dimensao), 1, f);	

    //salva as celulas
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            qtdItensGravados += fwrite(&celulas[i][j], sizeof(celula), 1, f);	
        }
    }

    if(qtdItensGravados != qtdItens) {
        printf("Erro ao gravar arquivo!");
    }else {
        printf("Arquivo gravado com sucesso!");
    }

    fclose(f);
}
