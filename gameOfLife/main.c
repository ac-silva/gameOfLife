#include <stdio.h>
#include <stdlib.h>

typedef struct __celula{
    int status;
    int x;
    int y;
    void (*p)(int);
} celula;

void getNumLinesAndColumns(int *, int *);
celula** allocAndInitialize(int, int);
void getCellAlive(celula**);
void printArray(celula**, int, int);
void nextGeneration(celula**, int, int);

void main(void){
    config();
    int lines   	 = 0;
    int columns 	 = 0; 
    int contGeration = 1;
    celula **celulas;
    
	//getQtdVizinhosVivos(**celulas, 1, 1);
    //View.dimensions(&linha, &coluna);
    
    getNumLinesAndColumns(&lines, &columns);
  	celulas = allocAndInitialize(lines, columns);
  	printArray(celulas, lines, columns);
  	
	printf("\n\n");
  	
	getCellAlive(celulas);
  	printArray(celulas, lines, columns);
  	
  	char resp;
  	do{
  		printf("\nGERACAO %d!!", ++contGeration);
  		nextGeneration(celulas, lines, columns);
  		printArray(celulas, lines, columns);
  		
  		//question
  		getc(stdin);
	    printf("\nDeseja saber como sera a proxima geracao? (s/n)\n");
	    fflush(stdin);
	    resp = getc(stdin);
  	}while(resp == 's' || resp == 'S');
}

void printArray(celula **celulas, int lines, int columns){
	int i, j;
    printf("\n\t");
     for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){
            printf("%d", celulas[i][j].status);
        }
        printf("\n\t");
    }
}

void nextGeneration(celula **celulas, int lines, int columns){
	celula **celulas2 = allocAndInitialize(lines, columns);
	int i, j;
	for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
			int qtdVizinhosVivos = getQtdVizinhosVivos(celulas2, i, j);
			if(qtdVizinhosVivos == 2 || qtdVizinhosVivos == 3){
				celulas2[i][j].status =  1;
			}
		}
	}
}

void getCellAlive(celula **celulas){
	printf("\nDefinir Celulas da primeira GERACAO!!\n");
	char resp;
	do{
		int x = 0, y = 0;
	    printf("Coordenada X (linha): ");
	    scanf("%d", &x);
	    printf("Coordenada Y (coluna): ");
	    scanf("%d", &y);
		celulas[x  - 1][y - 1].status = 1;
	    
	    getc(stdin);
	    printf("\nDeseja definir mais celulas? (s/n)\n");
	    fflush(stdin);
	    resp = getc(stdin);
	}while(resp == 's' || resp == 'S');
}

void getNumLinesAndColumns(int *lines, int *columns){
	printf("Definir MUNDO!!\n");
    printf("Qtd. Linhas: ");
    scanf("%d", lines);
    printf("Qtd. Colunas: ");
    scanf("%d", columns);
}

celula** allocAndInitialize(int lines, int columns){
	celula **celulas;
	int i, j;
	//alloc lines
	celulas = malloc(lines * sizeof(celula)); 
    for(i = 0; i < lines; i++){
    	//alloc columns of lines
		celulas[i] = malloc(columns * sizeof(celula)); 
    }
    
    //initializes
    for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
    		celulas[i][j].status = 0;
			celulas[i][j].x      = i;
			celulas[i][j].y      = j; 
    	}
    }
    return celulas;
}

int getQtdVizinhosVivos(celula **celulas, int x, int y){
	int qtdVizinhosVivos = 0;
	celula vizinhos[8];
	
	//int vizinhoA_x = x-1;
    //int vizinhoA_y = y-1;
	vizinhos[0] = celulas[ x - 1 ] [ y - 1 ];
	
	//int vizinhoB_x = x-1;
    //int vizinhoB_y = y;
    vizinhos[1] = celulas[ x - 1 ] [ y ];
    
    
    //int vizinhoC_x = x-1;
    //int vizinhoC_y = y+1;
    vizinhos[2] = celulas[ x - 1 ] [ y + 1 ];
    
	//int vizinhoD_x = x;
	//int vizinhoD_y = y-1;
	vizinhos[3] = celulas[ x ] [ y - 1];
	
	//int vizinhoE_x = x;
	//int vizinhoE_y = y+1;
	vizinhos[4] = celulas [ x ] [ y + 1 ];
	
	//int vizinhoF_x = x + 1;
	//int vizinhoF_y = y - 1;
	vizinhos[5] = celulas [ x + 1 ] [ y - 1 ];
	
	//int vizinhoG_x = x + 1;
	//int vizinhoG_y = y;
	vizinhos[6] = celulas[ x + 1 ] [ y ]; 
	 
	//int vizinhoH_x = x + 1;
	//int vizinhoH_y = y + 1;
	vizinhos[7] = celulas [ x + 1] [ y + 1 ];
	
	int i;
	for(i = 0; i < 8; i++){
		if(vizinhos[i].status){
			qtdVizinhosVivos++;
		}
	}
	
	return qtdVizinhosVivos;
}
