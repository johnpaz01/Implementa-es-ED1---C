#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *noEsquerdo;
    struct no *noDireito;
} No;

typedef No *arvoreBin;

arvoreBin createArv()
{
    return NULL;
}

void estaVazia(arvoreBin *arv)
{
    if (*arv == NULL)
    {
        printf("\nA arvore esta vazia\n");
    }
    else
    {
        printf("\nA arvore nao esta vazia\n");
    }
}

void inserirNaRaiz(arvoreBin *arv, int dado)
{
    if (*arv != NULL)
    {
        printf("\nImpossivel inserir na raiz, ela ja esta preenchida\n");
        return;
    }
    No *NoRaiz = (No *)malloc(sizeof(No));
    if (NoRaiz == NULL)
    {
        printf("\nErro ao alocar memoria!\n");
        return;
    }
    NoRaiz->dado = dado;
    NoRaiz->noDireito = NULL;
    NoRaiz->noEsquerdo = NULL;
    *arv = NoRaiz;
    printf("\nRaiz criada com sucesso!\n");
}

No *buscarNo(arvoreBin arv, int valor)
{
    if (arv == NULL)
    {
        return NULL;
    }
    if (arv->dado == valor)
    {
        return arv;
    }
    No *achou = buscarNo(arv->noEsquerdo, valor);
    if (achou == NULL)
    {
        achou = buscarNo(arv->noDireito, valor);
    }
    return achou;
}

void inserirAesquerda(arvoreBin arv, int Vpai, int Vfilho)
{
    No *pai = buscarNo(arv, Vpai);
    if (pai == NULL)
    {
        printf("\nErro, o pai nao existe!\n");
        return;
    }
    if (pai->noEsquerdo != NULL)
    {
        printf("\nErro, o no esquerdo de %d ja existe!\n", Vpai);
        return;
    }
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("\nErro ao alocar memoria!\n");
        return;
    }
    novoNo->dado = Vfilho;
    novoNo->noEsquerdo = NULL;
    novoNo->noDireito = NULL;
    pai->noEsquerdo = novoNo;
    printf("\nNo %d inserido a esquerda de %d com sucesso!\n", Vfilho, Vpai);
}

void inserirAdireita(arvoreBin arv, int Vpai, int Vfilho)
{
    No *pai = buscarNo(arv, Vpai);
    if (pai == NULL)
    {
        printf("\nErro, o pai nao existe!\n");
        return;
    }
    if (pai->noDireito != NULL)
    {
        printf("\nErro, o no direito de %d ja existe!\n", Vpai);
        return;
    }
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("\nErro ao alocar memoria!\n");
        return;
    }
    novoNo->dado = Vfilho;
    novoNo->noEsquerdo = NULL;
    novoNo->noDireito = NULL;
    pai->noDireito = novoNo;
    printf("\nNo %d inserido a direita de %d com sucesso!\n", Vfilho, Vpai);
}

void imprimirSequencia(arvoreBin arv, int profundidade)
{
    if (arv == NULL)
    {
        return;
    }
    printf("%d(%d)", arv->dado, profundidade);
    if (arv->noEsquerdo != NULL)
    {
        printf(" <- ");
        imprimirSequencia(arv->noEsquerdo, profundidade + 1);
    }
    if (arv->noDireito != NULL)
    {
        printf(" -> ");
        imprimirSequencia(arv->noDireito, profundidade + 1);
    }
}

void liberarArvore(arvoreBin arv)
{
    if (arv == NULL)
    {
        return;
    }
    liberarArvore(arv->noEsquerdo); // Libera a subárvore esquerda
    liberarArvore(arv->noDireito);  // Libera a subárvore direita
    free(arv);                      // Libera o nó atual
}

int main()
{
    arvoreBin arvore = createArv();

    inserirNaRaiz(&arvore, 1);
    inserirAesquerda(arvore, 1, 2);
    inserirAdireita(arvore,1, 421);
    inserirAdireita(arvore, 2, 3);
    inserirAesquerda(arvore, 2, 8);
    inserirAdireita(arvore, 8, 124);
    inserirAdireita(arvore, 124, 221);
    inserirAesquerda(arvore, 221, 92);
    inserirAdireita(arvore, 92, 8214);
    inserirAdireita(arvore, 221, 214);

    imprimirSequencia(arvore, 0);
    liberarArvore(arvore);
    return 0;
}
