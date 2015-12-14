#include "def.h"

void config(model *m, view *v){
    //model
    m->alocarInicializar          = &alocarInicializar;
    m->proximaGeracao             = &proximaGeracao;
    m->obterQtdVizinhosVivos      = &obterQtdVizinhosVivos;
    m->salvarMatriz               = &salvarMatriz;
    m->carregarMatriz             = &carregarMatriz;

    //view
    v->obterNumeroDeLinhasColunas = &obterNumeroDeLinhasColunas;
    v->obterCelulasVivas          = &obterCelulasVivas;
    v->imprimirGeracao            = &imprimirGeracao;
    v->exibirProximaGeracao       = &exibirProximaGeracao;
    v->carregarOuDefinir          = &carregarOuDefinir;
}
