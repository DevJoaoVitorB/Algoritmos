#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node* p;
} Node;

Node* inicio = NULL;

// void print()
// {
//     if (inicio == NULL)
//     {
//         printf("Lista Ligada Vazia!");
//     } else {

//     }
// }

void insert()
{
    Node* new = (Node*)malloc(sizeof(Node));
    int n = 0;

    printf("Informe o Número a ser Inserido na Lista: ");
    scanf("%d", &n);
    new->number = n;

    if (inicio == NULL)
    {
       
    } else {
        
    }
}

int menu()
{
    int value = 0;
    printf("--- Operações com Listas Ligadas em C --- \n");
    printf("Informe - [1]Inserir [2]Remover [3]Buscar [4]Imprimir [5]Tamanho [6]Vazia [0]Sair \n");
    scanf("%d", &value);
    return value;
}

int main()
{
    int value = 0;
    do
    {
        value = menu();
        switch (value)
        {
        case 1:
            insert();
            break;
        // case 2:
        //     del();
        //     break;
        // case 3:
        //     search();
        //     break;
        // case 4:
        //     print();
        //     break;
        // case 5:
        //     size();
        //     break;
        // case 6:
        //     void_();
        case 0:
            break;
        default:
            printf("Valor Inserido Inválido!");
            break;
        }
    } while (value != 0);

    return 0;
}