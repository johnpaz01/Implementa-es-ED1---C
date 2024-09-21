#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *noEsquerdo;
    struct no *noDireito;
} tNo; // eh o apelido do tipo no

typedef tNo *arvoreBIN; // isso aqui nesse codigo em especifico eh
// um outro ponteiro que ajuda nas proximas funcoes pra nao se confundi, mas ela aponta pro tipo tNo

arvoreBIN createArv()
{
    return NULL; // A árvore é inicializada como vazia.
}

void estaVazia(arvoreBIN *arv)
{
    if (*arv == NULL)
    {
        printf("\nA arvore esta vazia\n");
    }
    else
    {
        printf("A arvore nao esta vazia");
    }
}

void inserirNaRaiz(arvoreBIN *arv, int dado)
{
    if (*arv != NULL)
    {
        printf("Impossivel inserir na raiz");
        return;
    }
    tNo *root = (tNo *)malloc(sizeof(tNo));
    if (root == NULL)
    {
        printf("Erro de memoria");
        return;
    }

    root->dado = dado;
    root->noDireito = NULL;
    root->noEsquerdo = NULL;
    *arv = root;
    printf("\nRaiz criada com sucesso!\n");
}

void printArv(arvoreBIN root)
{
    if (root != NULL)
    {
        // Visita o nó esquerdo
        printArv(root->noEsquerdo);

        // Visita o nó atual (raiz)
        printf("%d ", root->dado);

        // Visita o nó direito
        printArv(root->noDireito);
    }
}

arvoreBIN busca(arvoreBIN arv, int content)
{
    arvoreBIN achou;

    if (arv == NULL)
    {
        return NULL;
    }
    if (arv->dado == content)
    {
        return arv;
    }

    achou = busca(arv->noEsquerdo, content);
    if (achou == NULL)
    {
        achou = busca(arv->noDireito, content);
    }
    return achou;
}

void inserirAdireita(arvoreBIN arv, int Vpai, int Vfilho)
{

    tNo *f, *p, *novoNo;

    if (arv == NULL)
    {
        printf("A arvore esta vazia");
        return;
    }

    f = busca(arv, Vfilho);

    if (f != NULL)
    {
        printf("\nErro, o elemento ja existe!\n");
        return;
    }
    p = busca(arv, Vpai);
    if (p == NULL)
    {
        printf("\nErro, o pai nao existe!\n");
        return;
    }
    if (p->noDireito != NULL)
    {
        printf("\n Erro, o no direito ja existe!\n");
        return;
    }

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
    {
        printf("\nErro na alocacao de memoria!\n");
        return;
    }
    novoNo->dado = Vfilho;
    novoNo->noDireito = NULL;
    novoNo->noEsquerdo = NULL;
    p->noDireito = novoNo;
    printf("\nNo inserido com sucesso!\n");
}

void inserirAesquerda(arvoreBIN arv, int Vpai, int Vfilho)
{

    tNo *f, *p, *novoNo;

    if (arv == NULL)
    {
        printf("A arvore esta vazia");
        return;
    }

    f = busca(arv, Vfilho);

    if (f != NULL)
    {
        printf("\nErro, o elemento ja existe!\n");
        return;
    }
    p = busca(arv, Vpai);
    if (p == NULL)
    {
        printf("\nErro, o pai nao existe!\n");
        return;
    }
    if (p->noEsquerdo != NULL)
    {
        printf("\n Erro, o no direito ja existe!\n");
        return;
    }

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
    {
        printf("\nErro na alocacao de memoria!\n");
        return;
    }
    novoNo->dado = Vfilho;
    novoNo->noDireito = NULL;
    novoNo->noEsquerdo = NULL;
    p->noEsquerdo = novoNo;
    printf("\nNo inserido com sucesso!\n");
}


int main()
{
    arvoreBIN arv = createArv(); // Corrigido para usar createArv()

    estaVazia(&arv);

    inserirNaRaiz(&arv, 21);
    printf("\nRAZ: ");
    printArv(arv);
    inserirAdireita(arv, 21, 10);
   inserirAesquerda(arv, 10, 32);
    printf("\nPrintando a arvore: \n");
    printArv(arv);
    inserirAdireita(arv, 10, 46);
    inserirAesquerda(arv, 32, 77);
    inserirAesquerda(arv,  77, 79);
    inserirAdireita(arv, 77, 1);
      printf("\nPrintando a arvore: \n");
    printArv(arv);

    return 0;
}
