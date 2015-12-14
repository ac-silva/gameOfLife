#include "def.h"

/**
 * Inicio do programa
 * @return void
 */
void main(void){
    model model;
    view  view;
    config(&model, &view);

    celula **celulas;
    int linhas   	   = 0;
    int colunas 	   = 0; 
    int contGeracao    = 1;

    //receber o tamanho da matriz
    view.obterNumeroDeLinhasColunas(&linhas, &colunas);

    if(view.carregarOuDefinir()){
        //carrega a partir do arquivo
        celulas = model.carregarMatriz(&linhas, &colunas, BANCO_DE_DADOS);
    }else{
        //alocar e inicializar celulas
        celulas = model.alocarInicializar(linhas, colunas);

        //imprimir a geracao zero
        view.imprimirGeracao(celulas, linhas, colunas);
        printf("\n\n");

        //receber do usuario a definicao da primeira geracao
        view.obterCelulasVivas(celulas, linhas, colunas);
    }
    //imprimir primeira geracao
    view.imprimirGeracao(celulas, linhas, colunas);

    //exibir proximas geracaoes
    view.exibirProximaGeracao(&contGeracao, celulas, linhas, colunas);
}
