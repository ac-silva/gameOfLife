#include <stdio.h>
#include <stdlib.h>
#define ICON_VIVO  '*'
#define ICON_MORTO '.'
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
celula** nextGeneration(celula**, int, int);
int getQtdVizinhosVivosExtreme(celula**, int, int, int, int);


void main(void){
    config();


    celula **celulas;
    int lines   	 = 0;
    int columns 	 = 0; 
    int contGeration = 1;
    
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
  		celulas = nextGeneration(celulas, lines, columns);
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
            char rp = (celulas[i][j].status) ? ICON_VIVO : ICON_MORTO;
            printf("%c", rp);
        }
        printf("\n\t");
    }
}

celula** nextGeneration(celula **celulas, int lines, int columns){
	celula **celulas2 = allocAndInitialize(lines, columns);
	int i, j;
	for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
			int qtdVizinhosVivos = 0;
			
            if(i != 0 && j != 0 && i != (lines-1) && j != (columns-1)){
                qtdVizinhosVivos = getQtdVizinhosVivos(celulas, i, j);
			}else{
				qtdVizinhosVivos = getQtdVizinhosVivosExtreme(celulas, i, j, lines, columns);
			}
            if(qtdVizinhosVivos == 3 || (celulas[i][j].status && qtdVizinhosVivos == 2)){
                celulas2[i][j].status =  1;
            }
			
		}
	}
	return celulas2;
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


int getQtdVizinhosVivosExtreme(celula **celulas, int x, int y, int lines, int columns){
	int qtdVizinhosVivos = 0;
	celula vizinhos[8];
	
	int prev_x = 0;
	int prev_y = 0;
	int next_x = 0;
	int next_y = 0;
	
	//primeira linha
	if(x == 0){
		prev_x = lines - 1;
	}else{
		prev_x = x - 1;
	}
	
	//última linha
	if(x == (lines-1)){
		next_x = 0;
	}else{
		next_x = x + 1;
	}
	
	//primeira coluna
	if(y == 0){
		prev_y = lines - 1;
	}else{
		prev_y = y - 1;
	}
	
	if(y == (columns-1)){
		prev_y = 0;
	}else{
		prev_y = columns-1;
	}
	
	// [linha - 1] [coluna - 1]
	vizinhos[0] = celulas[ prev_x ] [ prev_y ];

	// [linha - 1] [coluna]
    vizinhos[1] = celulas[ prev_x ] [ y ];

    // [linha - 1] [coluna + 1]
    vizinhos[2] = celulas[ prev_x ] [ next_y ];

	// [linha] [coluna - 1]
	vizinhos[3] = celulas[ x ] [ prev_y ];
	
	// [linha] [coluna + 1]
	vizinhos[4] = celulas[ x ] [ next_y ];
	
	// [linha + 1] [coluna - 1]
	vizinhos[5] = celulas[ next_x ] [ prev_y ];
	
	// [linha + 1] [coluna]
	vizinhos[6] = celulas[ next_x ] [ y ]; 
	 
	// [linha + 1] [coluna + 1]
	vizinhos[7] = celulas[ next_x ] [ next_y ];
	
	int i;
	for(i = 0; i < 8; i++){
		if(vizinhos[i].status){
			qtdVizinhosVivos++;
		}
	}
	
	return qtdVizinhosVivos;
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
	vizinhos[4] = celulas[ x ] [ y + 1 ];
	
	//int vizinhoF_x = x + 1;
	//int vizinhoF_y = y - 1;
	vizinhos[5] = celulas[ x + 1 ] [ y - 1 ];
	
	//int vizinhoG_x = x + 1;
	//int vizinhoG_y = y;
	vizinhos[6] = celulas[ x + 1 ] [ y ]; 
	 
	//int vizinhoH_x = x + 1;
	//int vizinhoH_y = y + 1;
	vizinhos[7] = celulas[ x + 1] [ y + 1 ];
	
	int i;
	for(i = 0; i < 8; i++){
		if(vizinhos[i].status){
			qtdVizinhosVivos++;
		}
	}
	
	return qtdVizinhosVivos;
}
