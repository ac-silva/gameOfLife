#include "celula.h"
/**
	VIEW
**/
typedef struct __view{
    void (*obterNumeroDeLinhasColunas)(int *, int *);
    void (*obterCelulasVivas)(celula **);
    void (*imprimirGeracao)(celula **, int, int);
    void (*exibirProximaGeracao)(int, celula**, int, int);
} view;

void obterNumeroDeLinhasColunas(int *, int *);
void obterCelulasVivas(celula**);

/**
	MODEL
**/
celula** alocarInicializar(int, int);
celula** proximaGeracao(celula **, int, int);
int obterQtdVizinhosVivos(celula **, int, int, int, int);

typedef struct __model{
    celula** (*alocarInicializar)(int, int);
    celula** (*proximaGeracao)(celula **, int, int);
    int (*obterQtdVizinhosVivos)(celula **, int, int, int, int);
} model;

