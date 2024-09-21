#include <stdio.h>

void isEmpity(int tam)
{
    if (tam == 0)
    {
        printf("\nA lista esta vazia!");
    }
}

void isFull(int tam, int tamMax)
{
    if (tam >= tamMax)
    {
        printf("\nA lista esta cheia!");
    }
}

void sizeList(int tam)
{
    printf("\nTamanho da lista = [%d]", tam);
}

void modList(int vetor[], int pos, int mod, int tamMax)
{
    int numAnt;
    if ((pos <= 0) || pos > (tamMax + 1))
    {
        printf("\nERRO, limits outside the standards");
    }
    else
    {
        numAnt = vetor[pos - 1];
        vetor[pos - 1] = mod;
        printf("\nNumero modificado com sucesso\nNum anterior: [%d] -> [%d]", numAnt, mod);
    }
}



void insertVetor(int vetor[], int tam, int tamMax, int pos, int elem){
    int i, a, p;
if((tam>=tamMax) || ((pos > tamMax+1)|| (pos<0))){
        printf("\nERRO, limits outside the standards");
}else{
    for(i = pos -1; i < tam; i++){
        a = vetor[i];
        vetor[i] = elem;
        elem = a;
    }
}
}


void delVetor(int vetor[], int tam, int tamMax, int pos){
    int i, a;
if(((pos > tamMax+1)|| (pos<0))){
        printf("\nERRO, limits outside the standards");
}else{
    a = vetor[pos - 1];
    for(i = pos -1; i < tam; i++){
       vetor[i] = vetor[i+1];
    }
}
printf("%d", a);
}



int main()
{
    int tam = 5; // tamanho inicial
    int tamMax = 100;
    int vetor[tamMax]; //= {1, 2, 3, 4, 5}; // inicializando vetor com alguns valores

    // Verificar se a lista está vazia
    isEmpity(tam);

    // Verificar se a lista está cheia
    isFull(tam, tamMax);

    // Mostrar o tamanho da lista
    sizeList(tam);

    // Modificar um valor na lista
    modList(vetor, 3, 10, tamMax);

    // Inserir um novo valor na lista
    insertVetor(vetor, tam, tamMax, 2, 99);
    tam++; // aumentar o tamanho após a inserção

    // Mostrar o vetor após inserção
    printf("\nVetor após inserção: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }

    // Mostrar o tamanho da lista após inserção
    sizeList(tam);

    return 0;
}
