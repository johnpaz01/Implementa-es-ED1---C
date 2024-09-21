#include <stdio.h>

void sort(int vetor[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > aux; j--) {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = aux;
    }
}

void printVetor(int v[], int n) {
    printf("\nIniciando Vetor!\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("Vetor: [%d] = %d\n", i + 1, v[i]);
    }
    printf("\nVetor finalizado!\n");
}

int main() {
    FILE *file;
    int tam = 10001;
    int vetor[tam], n = 0;
    
    file = fopen("C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd1\\instancias-num\\num.10000.2.in", "r");
    if (file == NULL) {
        printf("\nErro ao ler o arquivo!\n");
        return 1;
    }
    
    while (fscanf(file, "%d", &vetor[n]) != EOF && n < tam) {
        n++;
    }
    
    fclose(file);

    printVetor(vetor, n);
    sort(vetor, n);  
    printVetor(vetor, n);

    return 0;
}
