#include <stdio.h>
#include <stdlib.h>

typedef struct __celula{
    int status;
    int x;
    int y;
} celula;

int      obterQtdVizinhosVivos(celula**, int, int, int, int);
void     imprimirGeracao(celula**, int, int);
void     exibirProximaGeracao(int *, celula**, int, int);
celula** alocarInicializar(int, int);
celula** proximaGeracao(celula**, int, int);

