#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
typedef struct no No;

struct no
{
int valor;
No* proximo;
};


struct lista
{
    No* primeiro;
};



Lista* criarLista(void){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->primeiro = NULL;
    return l;
}

void InsertInList(Lista* l, int valor){

No* NovoNo = (No*)malloc(sizeof(No));
NovoNo->proximo = l->primeiro;
NovoNo->valor = valor;
l->primeiro= NovoNo;

}

void print_list(Lista* l) {
    No* p;  // Declare a vari�vel fora do loop
    printf("\n====\nInicio da Lista\n====\n");
    for (p = l->primeiro; p != NULL; p = p->proximo) {
        printf("PnM:[%p] - Valor: [%d]\n", (void*)p, p->valor);
    }
    printf("====\nFim da Lista\n====\n");
}
void clear_list(Lista* l){

printf("\n====\nLimpando a Lista\n====\n====");

No* p = l-> primeiro;
while (p != NULL) {
No* t = p-> proximo; 
free(p); 
p = t; 
}
free(l);
printf("\n====\nFIM da limpeza da Lista\n====\n====");
}

int main(){
    
Lista * l = criarLista();
	InsertInList(l, 21);
	InsertInList(l, 33);
	InsertInList(l, 20);
	printf("digite outro numero: ");
	int n;
	scanf("%d", &n);
	InsertInList(l, n);
		printf("digite outro numero: ");
	scanf("%d", &n);
		InsertInList(l, n);
	InsertInList(l, 210);
	print_list(l);
    clear_list(l);

    return 0;
}
