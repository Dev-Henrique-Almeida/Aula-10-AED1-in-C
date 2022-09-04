#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct pilha{
    int notas;
    struct pilha* prox;
}Nota;


typedef struct fila {
int tam;
int inicio;
char vet[N][50];
struct pilha* notas[N];
}Fila;


Fila* iniciarFila(){
Fila* fila = (Fila*)malloc(sizeof(Fila));
fila->tam = 0; //inicializa a fila vazia;
fila->inicio = 0; //escolhe uma posição inicial;
return fila;
}

Nota* geradorNota(){
    Nota* notaPilha = (Nota*)malloc(sizeof(Nota));
    notaPilha->prox = NULL;
    return notaPilha;
}

Fila* inserirFila(Fila* fila, char* nome){
int fim;
if (fila->tam == N){
    printf("\n----------------------------\n\n");
    printf ("   Fila não tem espaço disponível");
    printf("\n----------------------------\n\n");
    }
    else
    {
        fim = (fila->inicio + fila->tam)%N; //cálculo do índice do último elemento
        strcpy(fila->vet[fim], nome);
        fila->notas[fim] = geradorNota();
        fila->tam += 1;
    }

}

Nota* iniciarPilha(){
    return NULL;
}

Fila* removerFila(Fila *fila)
{

    if (fila->tam == 0 )
    {
        printf("\n----------------------------\n\n");
        printf("     A Fila esta vazia!\n");
        printf("\n----------------------------\n\n");
        return fila;
    }
    else
    {
        printf("\n-------------------------------\n\n");
        printf(" Informacao removida: %s\n", fila->vet[fila->inicio]);
        printf("\n-------------------------------\n\n");
        fila->inicio = (fila->inicio + 1) % N;
        fila->tam--;
        return fila;
    }
}

Nota* inserirNota (Nota* notas){
    int opc = 0, nota;
    while(opc != 2)
    {
        Nota* aux = (Nota*)malloc(sizeof(Nota));
        printf("\nInforme a nota que deseja adicionar ao aluno: ");
        scanf("%d", &nota);
        if(notas == NULL)
        {
            aux->notas = nota;
            aux->prox = NULL;
        }            
        else if(notas != NULL)
        {
            aux->notas = nota;
            aux->prox = notas;
        }
        printf("\nDeseja inserir outra nota? \n 1 - Sim \n 2 - Nao \n");
        scanf("%d", &opc);
        if(opc == 1)
        {
            notas = aux;
        }
        else
        {
            return aux;
        }
    }    
}

Nota* removerNota(Nota* notas){

    Nota* aux = (Nota*)malloc(sizeof(Nota));
    if(notas == NULL)
    {
        printf(" A Pilha esta vazia!\n");
        return NULL;
    }         
    else{   
    Nota* aux = (Nota*)malloc(sizeof(Nota));
        printf("Nota removida: %d\n", notas->notas);
        aux = notas;
        aux = notas->prox;
        free(notas);
        return aux;        
    }
    return notas;
}

int buscarAluno (Fila* fila, char* nome){
int i, nota;
Nota* aluno = (Nota*)malloc(sizeof(Nota));
if(fila != NULL){
    for (i = fila->inicio; i < fila->tam; i++){
        if (strcmp(fila->vet[i], nome) == 0)
        {
            return i;
        }
    

        }
    return -1;
    }
    else
    {
        return -1;
    }
}

void visualizarNotas(Nota* notas){
    while (notas->prox != NULL)
    {
        printf("%d ", notas->notas);
        notas = notas->prox;
    }
    
}



void visualizar(Fila* fila)
{   
    int fim = (fila->inicio + fila->tam)%N;
    int i = fila->inicio;
    for(i; i<fim; i++)
    {
        printf("\n----------------------------\n");
        printf("Nome: %s ", fila->vet[i]);
        visualizarNotas(fila->notas[i]);
        
    }
    printf("\n----------------------------\n\n");
    
}


int main(){
    system("clear");
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    Nota* pilha = (Nota*)malloc(sizeof(Nota));
    int aluno;
    pilha = iniciarPilha();
    fila = iniciarFila();
    int opc;
    char info[20];

    
    do{
        
        printf("    Informe uma opcao: \n\n   1 - Inserir Aluno \n   2 - Remover Aluno \n   3 - Inserir Nota \n   4 - Remover Nota \n   5 - Visualizar Alunos e Notas \n   6 - Sair\n");
        scanf("%d", &opc);
        
        if(opc == 1)
        {
            
            printf("Insira uma informacao a ser adicionada: ");
            scanf("%s", info);
            fila = inserirFila(fila, info);
            system("clear");
        }
        else if(opc == 2)
        {
            system("clear");
            fila = removerFila(fila);
        }    
        else if (opc == 3)
        {
            system("clear");
            visualizar(fila);
            
            printf("Informe o nome do aluno que deseja adicionar a nota: ");
            scanf("%s", info);
            aluno = buscarAluno(fila, info);
            if(aluno == -1)
            {   
                printf("\n----------------------------\n\n");
                printf("      Aluno nao encontrado\n");
                printf("\n----------------------------\n\n");
            }
            else
            {
                fila->notas[aluno] = inserirNota(fila->notas[aluno]);  
            }
        }
        else if(opc == 4)
        {
            system("clear");
            visualizar(fila);
            printf("Informe o nome do aluno que deseja remover uma nota: ");
            scanf("%s", info);
            aluno = buscarAluno(fila, info);
            printf("\n----------------------------\n\n");
            printf("Nome: %s\n", fila->vet[aluno]);
            fila->notas[aluno] = removerNota(fila->notas[aluno]);
            printf("\n----------------------------\n\n");

        }
        else if(opc == 5)
        {
            system("clear");
            visualizar(fila);

        }
        else if (opc == 6)
        {
            system("clear");
            printf("Laboratorio 04 - Feito por Henrique de Almeida Silva, 02/09/22\n");
        }
    }
    while(opc != 6);

    return 0;
}