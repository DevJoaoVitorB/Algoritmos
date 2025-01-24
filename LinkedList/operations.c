#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node* p;
} Node;

Node* init = NULL;

void void_()
{
    if(init == NULL)
    {
        printf("Lista Ligada está Vazia! \n");
    } else {
        printf("Lista Ligada não está Vazia! \n");
    }  
}

void size_()
{
    if (init == NULL)
    {
        printf("Lista Ligada Vazia! \n");
    } else {
        Node* size = init;
        int qtd = 0;
        while(size != NULL)
        {
            qtd++;
            size = size->p;
        }
        printf("Quantidade de Valores na Lista Ligada: %d \n", qtd); 
    }
}

void print_()
{
    if (init == NULL)
    {
        printf("Lista Ligada Vazia! \n");
    } else {
        Node* print = init;
        int value = 1;
        while(print != NULL)
        {
            printf("%d° Valor - %d \n", value, print->number);
            print = print->p;
            
            value++;
        }
    }
}

void search_()
{
    if(init == NULL){
        printf("Lista Ligada Vazia! \n");
    } else {
        int value = 0, position = 0, not_found = 0;
        printf("Informe o Valor a ser Buscado na Lista Ligada: ");
        scanf("%d", &value);

        Node* search = init;
        while(search != NULL)
        {
            if (search->number == value)
            {
                printf("Valor %d Encontrado na Posição %d \n", value, position);
                not_found = 1;
                break;
            } else {
                search = search->p;
                not_found = 0;
            }

            position++;
        }

        if (not_found == 0)
        {
            printf("Valor %d não Encontrado! \n", value);
        }
    }
}

void del_()
{
    if (init == NULL)
    {
        printf("Lista Ligada Vazia! \n");
    } else {
        int value = 0, not_found = 0;
        printf("Informe o Valor a ser Removido da Lista Ligada: ");
        scanf("%d", &value);

        Node* del = init;

        if(del->number == value)
        {
            init = init->p;
            free(del);
        } else {
            while(del->p != NULL)
            {
                if(value == del->p->number)
                {
                    Node* t = del->p;
                    del->p = t->p;
                    free(t);
                    not_found = 1;
                } else {
                    del = del->p;
                    not_found = 0;
                }
            }
        }
    }
}

void insert_()
{
    Node* new = (Node*)malloc(sizeof(Node));
    int n = 0;

    printf("Informe o Número a ser Inserido na Lista: ");
    scanf("%d", &n);
    new->number = n;

    if (init == NULL)
    {
        init = new;
        init->p = NULL;
    } else {
        new->p = init;
        init = new;
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
            insert_();
            break;
        case 2:
            del_();
            break;
        case 3:
            search_();
            break;
        case 4:
            print_();
            break;
        case 5:
            size_();
            break;
        case 6:
            void_();
        case 0:
            break;
        default:
            printf("Valor Inserido Inválido!");
            break;
        }
    } while (value != 0);

    return 0;
}