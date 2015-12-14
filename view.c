#include "def.h"
/**
 * Recebe do usuario o numero de linhas e colunas da matriz
 * @param  int linhas
 * @param  int colunas
 * @return void
 */
void obterNumeroDeLinhasColunas(int *linhas, int *colunas){
    printf("Definir MUNDO!!\n");
    printf("Qtd. Linhas: ");
    scanf("%d", linhas);
    printf("Qtd. Colunas: ");
    scanf("%d", colunas);
}

/**
 * Recebe do usuario a definicao das celulas vivas a partir das coordenadas("x" e "y") - linha/coluna
 * @param  Array<celula> celulas
 * @return Array<celula>
 */
void obterCelulasVivas(celula **celulas, int linhas, int colunas){
    printf("\nDefinir Celulas da primeira GERACAO!!\n");
    char resp;
    do{
        int x = 0, y = 0;
        do{
            printf("Coordenada X (linha): ");
            scanf("%d", &x);
            if(x <= 0 || x > linhas){
                printf("Coordenada X deve ser um numero entre 1 e %d\n", linhas);
            }
        }while(x <= 0 || x > linhas);

        do{
            printf("Coordenada Y (coluna): ");
            scanf("%d", &y);
            if(y <= 0 || y > colunas){
                printf("Coordenada Y deve ser um numero entre 1 e %d\n", colunas);
            }
        }while(y <= 0 || y > colunas);
        celulas[x  - 1][y - 1].status = 1;

        getc(stdin);
        printf("\nDeseja definir mais celulas? (s/n)\n");
        fflush(stdin);
        resp = getc(stdin);
    }while(resp == 's' || resp == 'S');
}

/**
 * Imprime na tela a geracao
 * @param  Array<celula> celulas
 * @param  int linhas
 * @param  int colunas
 * @return void
 */
void imprimirGeracao(celula **celulas, int linhas, int colunas){
    int i, j;
    printf("\n\t");
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            char rp = (celulas[i][j].status) ? ICON_VIVO : ICON_MORTO;
            printf("%c", rp);
        }
        printf("\n\t");
    }
}

/**
 * Imprime a proxima geracao pelo menos uma vez e pergunta para o usuario se ele gostaria de saber
 * a proxi
 * @param  int contGeracao
 * @param  Array<celula> celulas
 * @param  int linhas
 * @param  int colunas
 * @return void
 */
void exibirProximaGeracao(int *contGeracao, celula **celulas , int linhas, int colunas){
    char resp;
    printf("\nGERACAO %d!!", ++*contGeracao);
    celulas = proximaGeracao(celulas, linhas, colunas);
    imprimirGeracao(celulas, linhas, colunas);
    opcoes(contGeracao, celulas, linhas, colunas);
}

/**
 * Verifica se o usuario gostaria de salvar a  geracao atual ou exibir a proxima geracao
 * @param  int contGeracao
 * @param  Array<celula> celulas
 * @param  int linhas
 * @param  int colunas
 * @return void
 */
void opcoes(int *contGeracao, celula **celulas, int linhas, int colunas){
    int opcao;
    printf("\n\n-----------------------\nSelecione Uma Opcao:\n-----------------------\n\n1 - Exibir proxima geracao\n2 - Salvar geracao atual\n3 - Fechar\n\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            exibirProximaGeracao(contGeracao, celulas, linhas, colunas);
        break;
        case 2:
            salvarMatriz(celulas, linhas, colunas, BANCO_DE_DADOS);
            printf("\n\n");
            opcoes(contGeracao, celulas, linhas, colunas);
        break;
        case 3:
            exit(0);
        break;
    }
}

int carregarOuDefinir(){
    char resp;
    do{
        getc(stdin);
        printf("\n\nVoce gostaria de iniciar a partir de uma geracao salva? (s/n)\n");
        fflush(stdin);
        resp = getc(stdin);
    }while(resp != 's' && resp != 'S' && resp != 'n' && resp && 'N');
    return (resp == 's' || resp == 's') ? 1 : 0;
}
