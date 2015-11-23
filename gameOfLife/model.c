typedef struct __model{
	void (*allocArray)(void);
} model;

/*void allocArray(celula **celulas){
	celulas = malloc(linha * sizeof(celula)); 
    for(i = 0; i < linha; i++){
    	celulas[i] = malloc(coluna * sizeof(celula)); 
    }
}*/
