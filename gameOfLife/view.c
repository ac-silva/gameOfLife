typedef struct __view{
	void (*getDimension)(int *, int *);
} View;

void getDimension(int *lines, int *columns){
	printf("Definir MUNDO!!\n");
    printf("Qtd. Linhas: ");
    scanf("%d", lines);
    printf("Qtd. Colunas: ");
    scanf("%d", columns);
}
