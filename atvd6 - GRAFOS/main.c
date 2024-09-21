#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct grafo Grafo;

struct grafo
{

    int numVerticies;
    int **matriz_adj;
};

Grafo *inicializa_grafo(int num_Verticies)
{
    int i;

    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->numVerticies = num_Verticies;
    g->matriz_adj = (int **)malloc(num_Verticies * sizeof(int *));

    for (i = 0; i < num_Verticies; i++)
    {
       g->matriz_adj[i] = (int *)calloc(num_Verticies, sizeof(int));  

    }
    return g;
}

void inserir_por_arquivo(Grafo *g, const char *nome_do_arquivo)
{
    int i, j;
    FILE *file = fopen(nome_do_arquivo, "r");
    if (file == NULL)
    {
        printf("Não foi possivel Localizar o arquivo\n");
        return;
    }

    for (i = 0; i < g->numVerticies; i++)
    {
        for (j = 0; j < g->numVerticies; j++)
        {

            fscanf(file, "%d", &(g->matriz_adj[i][j]));
        }
    }
    printf("Leitura Realizada com Sucesso!\n");
    fclose(file);
}

void bsf(Grafo *g, int inicio, int destino)
{
    printf("Iniciando busca em largura (BSF):\n");

    if (inicio >= g->numVerticies || destino >= g->numVerticies || inicio < 0 || destino < 0) {
        printf("Erro: vertice inicial ou destino fora do intervalo.\n");
        return;
    }

    int *fila = (int *)malloc(g->numVerticies * sizeof(int));
    bool *visitado = (bool *)malloc(g->numVerticies * sizeof(bool));
    int *anterior = (int *)malloc(g->numVerticies * sizeof(int));

    for (int i = 0; i < g->numVerticies; i++) {
        visitado[i] = false;
        anterior[i] = -1;
    }

    int frente = 0, tras = 0;
    fila[tras++] = inicio;
    visitado[inicio] = true;
    anterior[inicio] = -1;

    printf("Alocacao inciada com sucesso, verificando caminhos...\n");


    while (frente != tras) {
        int vertice_atual = fila[frente++];
        printf("Vertice atual: %d\n", vertice_atual);

        if (vertice_atual == destino) {
            break;
        }

        for (int i = 0; i < g->numVerticies; i++) {
            if (g->matriz_adj[vertice_atual][i] != 0 && !visitado[i]) {
                fila[tras++] = i;

                if (tras >= g->numVerticies) {
                    printf("Erro: Fila ultrapassou o limite!\n");
                    free(fila);
                    free(visitado);
                    free(anterior);
                    return;
                }

                visitado[i] = true;
                anterior[i] = vertice_atual;

                printf("Explorando vertice %d, vindo de %d\n", i, vertice_atual);
            }
        }
    }

    if (!visitado[destino]) {
        printf("...\n...\n...\n");
        printf("Nao ha caminho entre os vertices %d e %d.\n", inicio, destino);
    } else {
        printf("Caminho de %d para %d: ", inicio, destino);
        int atual = destino;
        while (atual != -1) {
            if (atual == destino) {
                printf("%d  ->", atual);
            } else {
                printf(" -> %d ", atual);
            }
            atual = anterior[atual];
        }
        printf("\n");
    }

    printf("\nLimpando residos...\n...\n");
    free(fila);
    free(visitado);
    free(anterior);
}


void dsf(Grafo *g, int inicio)
{
    printf("Iniciando busca em profundidade (DSF):\n");
    int *pilha = (int *)malloc(g->numVerticies * sizeof(int));
    bool *visitado = (bool *)malloc(g->numVerticies * sizeof(bool));
    int topo = -1;

    pilha[topo++] = inicio;
    visitado[inicio] = true;

    printf("Alocacao inciada com sucesso!\n");
    while (topo != -1)
    {

        int i, vertice_atual = pilha[topo--];
        printf("%d ", vertice_atual);

        for (i = 0; i < g->numVerticies; i++)
        {
            if (g->matriz_adj[vertice_atual][i] != 0 && !visitado[i])
            {
                pilha[++topo] = i;
                visitado[i] = true;
            }
        }
    }

    printf("\nLimpando residos...\n...\n");
    free(pilha);
    free(visitado);
}

int main()
{

    int op, opA;
    int init, finish;
    Grafo *g1 = inicializa_grafo(4);
    Grafo *g2 = inicializa_grafo(10);
    Grafo *g3 = inicializa_grafo(50);
    Grafo *g4 = inicializa_grafo(177);
    do
    {
        printf("Bem vindo ao executador de grafos\n Selecione uma opcao: ");
        printf("\n1.Busca em largura(BSF)\n2.Busca em profundidade(DSF)\n0.Sair\n-----> ");
        scanf("%d", &op);

        switch (op)
        {
            // inicio case BSF
        case 1:
            printf("\nSelecione o arquivo desejado\n1 - pcv4.txt");
            printf("\n2 - pcv10.txt\n3 - pcv50.txt\n4 - pcv177.txt\n--->");
            scanf("%d", &opA);
            // Inicio escolha do arquivo BSF
            switch (opA)
            {
            case 1:
                inserir_por_arquivo(g1, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv4.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                printf("Insira o destino: ");
                scanf("%d", &finish);
                bsf(g1, init, finish);
                break;
            case 2:
                inserir_por_arquivo(g2, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv10.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                printf("Insira o destino: ");
                scanf("%d", &finish);
                bsf(g2, init, finish);
                break;
            case 3:
                inserir_por_arquivo(g3,  "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv55.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                printf("Insira o destino: ");
                scanf("%d", &finish);
                bsf(g3, init, finish);
                break;
            case 4:
                inserir_por_arquivo(g4, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv177.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                printf("Insira o destino: ");
                scanf("%d", &finish);
                bsf(g4, init, finish);
                break;

            default:
                printf("Arquivo inexistente!");
                break;
            }
            // Final escolha do arquivo BSF
            break;
        // Final case BSF

        //====

        // Inicio case DSF
        case 2:
            printf("\nSelecione o arquivo desejado\n1 - pcv4.txt");
            printf("\n2 - pcv10.txt\n3 - pcv50.txt\n4 - pcv177.txt\n--->");
            scanf("%d", &opA);
            // Incio escolha do arquivo DSF
            switch (opA)
            {

            case 1:
                inserir_por_arquivo(g1, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv4.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                dsf(g1, init);
                break;
            case 2:
                inserir_por_arquivo(g2, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv10.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                dsf(g2, init);
                break;
            case 3:
                inserir_por_arquivo(g3, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv55.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                dsf(g3, init);
                break;
            case 4:
                inserir_por_arquivo(g4, "C:\\Users\\johnp\\OneDrive\\Desktop\\P4\\Ed1\\implementacoes ED1\\atvd6 - GRAFOS\\pcv177.txt");
                printf("Insira o inicio: ");
                scanf("%d", &init);
                dsf(g4, init);
                break;

            default:
                printf("Arquivo inexistente!");
                break;
            }
            // Final escolha do arquivo case DSF
            break;
            // Final case DSF
        case 0:
            printf("\nSaindo....\n");
            free(g1);
            free(g2);
            free(g3);
            free(g4);
            break;
        default:
            printf("\nOpcao nao cadastrada\n");
            break;
        }
    } while (op != 0);

    return 0;
}