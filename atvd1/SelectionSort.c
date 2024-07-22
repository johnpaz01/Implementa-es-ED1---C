#include <stdio.h>

void sort(int vetor[], int n) {
    int i, j, min_idx, aux;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        aux = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = aux;
    }
}

void printVetor(int v[], int n) {
    printf("\nIniciando Vetor!\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Vetor: [%d] = %d\n", i + 1, v[i]);
    }
    printf("Vetor finalizado!\n");
}

int main() {
    FILE *file;
    int vetor[10001], n = 0, i;

    file = fopen("C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd1\\instancias-num\\num.10000.2.in", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(file, "%d", &vetor[n]) != EOF) {
        n++;
    }

    fclose(file);
    printVetor(vetor, n);
    sort(vetor, n);
    printVetor(vetor, n);

    return 0;
}
