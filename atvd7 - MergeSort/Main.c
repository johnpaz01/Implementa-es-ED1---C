#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Adicionado para medição de tempo

// Função para mesclar dois subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copiando dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Índices iniciais dos dois subarrays
    int i = 0, j = 0;

    // Índice inicial do array mesclado
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla as metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para ler números de um arquivo e armazená-los em um vetor
int* readNumbersFromFile(const char* filename, int* size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    int *arr = NULL;
    int num;
    *size = 0;

    // Ler números do arquivo e armazenar no vetor
    while (fscanf(file, "%d", &num) != EOF) {
        arr = (int *)realloc(arr, (*size + 1) * sizeof(int));
        arr[*size] = num;
        (*size)++;
    }

    fclose(file);
    return arr;
}

int main() {
    const char *filename = "C:/Users/johnp/OneDrive/Desktop/P4/Ed1/implementacoes ED1/atvd7 - MergeSort/num_100000_4.in";  // Substitua pelo seu arquivo .in

    int size;
    int *arr = readNumbersFromFile(filename, &size);

    if (arr == NULL) {
        return 1;
    }

   /* printf("Array original: \n");
    printArray(arr, size);*/

    // Medição do tempo de execução do Merge Sort
    clock_t start, end;
    double cpu_time_used;

    // Inicia a contagem do tempo
    start = clock();

    // Chama o mergeSort
    mergeSort(arr, 0, size - 1);

    // Para a contagem do tempo
    end = clock();

    // Calcula o tempo total usado
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nArray ordenado: \n");
    printArray(arr, size);

    // Imprime o tempo gasto
    printf("\nTempo gasto pelo Merge Sort: %f segundos\n", cpu_time_used);

    free(arr);  // Liberar memória alocada dinamicamente
    return 0;
}
