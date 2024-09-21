#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
    int valor;
    No *proximo;
};

struct lista {
    No *primeiro;
    int tamanho;
};

int retornar_tamanho(Lista *l) {
    printf("\nTamanho da lista: %d\n", l->tamanho);
    return l->tamanho;
}

Lista *criar_lista(void) {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->tamanho = 0;
    return l;
}

bool esta_vazia(Lista *l) {
    if (l->tamanho == 0) {
        printf("\nA lista está vazia!\n");
        return true;
    } else {
        printf("\nExistem elementos na lista!\n");
        return false;
    }
}

void obter_modificar_valor(Lista *l) {
    int pos, val, i, ant;

    printf("\nInsira a posição que você deseja modificar: ");
    scanf("%d", &pos);

    if (pos - 1 >= l->tamanho || esta_vazia(l)) {
        printf("\nPosição não está presente na lista\n");
    } else {
        printf("\nInsira o valor que você deseja modificar: ");
        scanf("%d", &val);
        No *atual = l->primeiro;

        for (i = 0; i < pos - 1; i++) {
            atual = atual->proximo;
        }
        ant = atual->valor;
        atual->valor = val;
        printf("\nValor na posição %d modificado de [%d] para [%d]\n", pos, ant, val);
    }
}

void inserir_em_determinada_posicao(Lista *l) {
    int pos, val, i;

    printf("\nInsira a posição que você deseja inserir: ");
    scanf("%d", &pos);

    if (pos > l->tamanho || pos < 0) {
        printf("\nPosição não está presente na lista\n");
        return;
    }

    printf("\nInsira o valor que você deseja inserir: ");
    scanf("%d", &val);

    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = val;

    if (pos == 0) {
        novoNo->proximo = l->primeiro;
        l->primeiro = novoNo;
    } else {
        No *atual = l->primeiro;
        for (int i = 0; i < pos - 1; i++) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
    l->tamanho++;
    printf("\nValor [%d] inserido na posição [%d]\n", val, pos);
}

void retirar_elemento_determinada_posicao(Lista *l) {
    int pos, i;

    printf("\nInsira a posição que você deseja remover: ");
    scanf("%d", &pos);

    if (pos >= l->tamanho || esta_vazia(l)) {
        printf("\nPosição não está presente na lista\n");
        return;
    }

    No *atual = l->primeiro;
    No *anterior = NULL;

    if (pos == 0) {
        l->primeiro = atual->proximo;
        free(atual);
    } else {
        for (i = 0; i < pos; i++) {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = atual->proximo;
        free(atual);
    }

    l->tamanho--;
    printf("\nElemento na posição %d removido com sucesso\n", pos);
}

void print_todos_elementos_da_lista(Lista *l) {
    int i;
    if (esta_vazia(l)) {
        printf("A lista está vazia.\n");
        return;
    }

    No *atual = l->primeiro;
    for (i = 0; i < l->tamanho; i++) {
        printf("indice:[%d] - PnM:[%p] - Valor: [%d]\n", i + 1, (void *)atual, atual->valor);
        atual = atual->proximo;
    }
}

int main(void) {
    int op = 1;
    Lista *l = criar_lista();

    while (op != 0) {
        printf("\n======\nMENU\n======\n");
        printf("1. Esta vazia? \n");
        printf("2. Tamanho da Lista \n");
        printf("3. Modificar valor na lista \n");
        printf("4. Inserir um elemento em determinada posicao \n");
        printf("5. Retirar elemento de determinada posicao \n");
        printf("6. Visualizar lista \n");
        printf("0. Sair \n--> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                esta_vazia(l);
                break;
            case 2:
                retornar_tamanho(l);
                break;
            case 3:
                obter_modificar_valor(l);
                break;
            case 4:
                inserir_em_determinada_posicao(l);
                break;
            case 5:
                retirar_elemento_determinada_posicao(l);
                break;
            case 6:
                print_todos_elementos_da_lista(l);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao nao cadastrada!\n");
                break;
        }
    }

    return 0;
}
