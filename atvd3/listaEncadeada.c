#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
typedef struct no NO;

struct no{
	   int valor;
	   NO* proximo;
};


struct lista{
	NO* prim;
};


Lista* Criar_Lista(void){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prim = NULL;
	return l;
}



void insert_init(Lista* l, int valor){
	
	NO * NovoNo = (NO*)malloc(sizeof(NO));
	NovoNo->proximo = l->prim;
	NovoNo ->valor = valor;
	l->prim = NovoNo;
}

void print_list(Lista* l){
printf("\n====\n Inicio da Lista\n====\n");
	for (NO* p = l->prim; p!=NULL; p = p->proximo){
		printf("PnM:[%p] - Valor: [%d]\n",p->valor, p->valor);
	}
printf("\n====\n Fim da Lista\n====\n");
}

void clear_list(Lista* l){

printf("\n====\nLimpando a Lista\n====\n====");

NO* p = l-> prim;
while (p != NULL) {
NO* t = p-> proximo; 
free(p); 
p = t; 
}
free(l);
printf("\n====\nFIM da limpeza da Lista\n====\n====");
}



int main(){
	
	Lista * l = Criar_Lista();
	insert_init(l, 10);
	insert_init(l, 33);
	insert_init(l, 1);
	insert_init(l, 15);
	insert_init(l, 4);
	insert_init(l, 2);
	print_list(l);
	clear_list(l);
	printf("\n===\nMostrando a lista pos limpeza\n===\n");
	print_list(l);

	
	return 0;
}
