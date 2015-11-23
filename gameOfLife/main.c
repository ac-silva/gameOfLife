#include <stdio.h>
#include <stdlib.h>

typedef struct __celula{
    int status;
    int x;
    int y;
    void (*p)(int);
} celula;

void main(void){
    config();
    int lines  = 0;
    int columns = 0;
    int i, j;
    celula **celulas;
    
	//getQtdVizinhosVivos(**celulas, 1, 1);
    //View.dimensions(&linha, &coluna);
    
	printf("Definir MUNDO!!\n");
    printf("Qtd. Linhas: ");
    scanf("%d", &lines);
    printf("Qtd. Colunas: ");
    scanf("%d", &columns);
    
    celulas = malloc(lines * sizeof(celula)); 
    for(i = 0; i < lines; i++){
    	celulas[i] = malloc(columns * sizeof(celula)); 
    }

    printf("\n");
    int h = 0;
    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){
            celulas[i][j].status = h;
            printf("%d", celulas[i][j].status);
            h = (h == 0)?1:0;
        }
        printf("\n");
    }
    printf("%d", getQtdVizinhosVivos(celulas, 5, 5));
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
