#include "celula.h"
#define ICON_VIVO  '*'
#define ICON_MORTO '.'
#define BANCO_DE_DADOS "database.bin"

/**
	VIEW
**/
int carregarOuDefinir();
typedef struct __view{
    void (*obterNumeroDeLinhasColunas)(int *, int *);
    void (*obterCelulasVivas)(celula **, int, int);
    void (*imprimirGeracao)(celula **, int, int);
    void (*exibirProximaGeracao)(int *, celula**, int, int);
    int (*carregarOuDefinir)();
} view;

void opcoes(int *, celula **, int , int);
void obterNumeroDeLinhasColunas(int *, int *);
void obterCelulasVivas(celula**, int, int);

/**
	MODEL
**/
celula** alocarInicializar(int, int);
celula** proximaGeracao(celula **, int, int);
int  obterQtdVizinhosVivos(celula **, int, int, int, int);
void salvarMatriz(celula **, int, int, char[]);
celula** carregarMatriz(int *, int *, char[]);

typedef struct __model{
    celula** (*alocarInicializar)(int, int);
    celula** (*proximaGeracao)(celula **, int, int);
    int (*obterQtdVizinhosVivos)(celula **, int, int, int, int);
    void (*salvarMatriz)(celula **, int, int, char[]);
    celula** (*carregarMatriz)(int *, int *, char[]);
} model;

typedef struct __dimensao{
    int linhas;
    int colunas;
} dimensao;

