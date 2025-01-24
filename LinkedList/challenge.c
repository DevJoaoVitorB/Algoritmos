#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modelo de Paciente
typedef struct Patient
{
    int id;
    char name[100];
    int preferencial; // 1 - TRUE; 0 - FALSE
}Patient;

// Modelo de Fila
typedef struct Node
{
    struct Node* next;
    struct Patient patient;
}Node;

// Modelo de Médico
typedef struct Doctor
{
    char name[100];
    int patient_id;
    int patient_qtd; 
    int order; // 1 - Preferencial; 0 - Normal
}Doctor;

Doctor* x;
Doctor* y;
Doctor* z;
Node* x_list;
Node* y_list;
Node* z_list;

void doctors_create()
{
    x = (Doctor*) malloc(sizeof(Doctor));
    y = (Doctor*) malloc(sizeof(Doctor));
    z = (Doctor*) malloc(sizeof(Doctor));

    strcpy(x->name, "Escobar");     //Nome do Médico
    x->patient_id = 1;              //Próximo Número de Id dos Pacientes
    x->patient_qtd = 0;             //Quantidade de Pacientes Atendidos
    x->order = 1;                   //Atendimento Preferêncial

    strcpy(y->name, "Oliveira");
    y->patient_id = 1;
    y->patient_qtd = 0;
    y->order = 1;

    strcpy(z->name, "Silva");
    z->patient_id = 1;
    z->patient_qtd = 0;
    z->order = 1;
}

void service_(int doctor)
{
    switch (doctor)
    {
        case 1: // DOUTOR ESCOBAR
            if(x_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", x->name);
            } else {
                if(x->order == 0) // Normal
                {
                    Node* aux = x_list;
                    Node* back = NULL;
                    while(aux->next != NULL)
                    {
                        if(aux->next->patient.preferencial == 1 && aux->patient.preferencial == 0)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = x_list;
                                x_list = x_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            x->order = 1;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Normal
                    printf("Paciente %s foi atendido! \n", x_list->patient.name);
                    Node* temp = x_list;
                    x_list = x_list->next;
                    free(temp);

                } else { // Preferencial
                    Node* aux = x_list;
                    Node* back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->patient.preferencial == 1)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = x_list;
                                x_list = x_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            x->order = 0;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Preferencial
                    aux = x_list;
                    back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->next == NULL)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            back->next == NULL;
                            free(aux);
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }
                }
            }
            break;
        case 2: // DOUTOR OLIVEIRA
            if(y_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", x->name);
            } else {
                if(y->order == 0) // Normal
                {
                    Node* aux = y_list;
                    Node* back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->next->patient.preferencial == 1 && aux->patient.preferencial == 0)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = y_list;
                                y_list = y_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            y->order = 1;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Normal
                    printf("Paciente %s foi atendido! \n", z_list->patient.name);
                    Node* temp = y_list;
                    y_list = y_list->next;
                    free(temp);

                } else { // Preferencial
                    Node* aux = y_list;
                    Node* back = NULL;
                    while(aux->next != NULL)
                    {
                        if(aux->patient.preferencial == 1)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = y_list;
                                y_list = y_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            y->order = 0;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Preferencial
                    aux = y_list;
                    back = NULL;
                    while(aux->next != NULL)
                    {
                        if(aux->next == NULL)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            back->next == NULL;
                            free(aux);
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }
                }
            }
            break;
        case 3:
            if(z_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", z->name);
            } else {
                if(z->order == 0) // Normal
                {
                    Node* aux = z_list;
                    Node* back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->next->patient.preferencial == 1 && aux->patient.preferencial == 0)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = z_list;
                                z_list = z_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            z->order = 1;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Normal
                    printf("Paciente %s foi atendido! \n", z_list->patient.name);
                    Node* temp = z_list;
                    z_list = z_list->next;
                    free(temp);

                } else { // Preferencial
                    Node* aux = z_list;
                    Node* back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->patient.preferencial == 1)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            if(back == NULL)
                            {
                                Node* temp = z_list;
                                z_list = z_list->next;
                                free(temp);
                            } else {
                                back->next = aux->next;
                                free(aux);
                            }
                            z->order = 0;
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }

                    // Não Encontrou Preferencial
                    aux = z_list;
                    back = NULL;
                    while(aux != NULL)
                    {
                        if(aux->next == NULL)
                        {
                            printf("Paciente %s foi atendido! \n", aux->patient.name);
                            back->next == NULL;
                            free(aux);
                            return;
                        }
                        back = aux;
                        aux = aux->next;
                    }
                }
            }
            break;
        default:
            break;
    }
}

void list_(int doctor)
{
    Node* patient_list;
    Doctor* d;

    switch (doctor)
    {
        case 1: // DOUTOR ESCOBAR
            patient_list = x_list;
            d = x;
            break;
        case 2: // DOUTOR OLIVEIRA
            patient_list = y_list;
            d = y;
            break;
        case 3: // DOUTOR SILVA
            patient_list = z_list;
            d = z;
            break;
        default:
            printf("O doutor informado não existe! \n");
            return;
    }

    if(patient_list == NULL)
    {
        printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", d->name);
    } else {
        printf("Lista de Pacientes do Doutor %s", d->name);
        while(patient_list != NULL)
        {
            Patient new_patient = patient_list->patient;
            if(new_patient.preferencial == 0) // Preferencial FALSE
            {
                printf("\n\t%d - %s - Normal", new_patient.id, new_patient.name);
            } else { // Preferencial TRUE
                printf("\n\t%d - %s - Preferencial", new_patient.id, new_patient.name);
            }
            patient_list = patient_list->next;
        }
    }
}

void exit_(int patient, int doctor)
{
    switch (doctor)
    {
        case 1: // DOUTOR ESCOBAR
            if(x_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", x->name);
            } else {
                Node* aux = x_list;
                Node* back = NULL;
                while(aux != NULL)
                {
                    if(aux->patient.id == patient)
                    {
                        if(back == NULL)
                        {
                            Node* temp = x_list;
                            x_list = x_list->next;
                            free(temp);
                        } else {
                            back->next = aux->next;
                            free(aux);
                        }
                        return;
                    }
                    back = aux;
                    aux = aux->next;
                }
            }
            printf("\n\tPaciente não encontrado! \n");
            break;
        case 2: // DOUTOR OLIVEIRA
            if(y_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", y->name);
            } else {
                Node* aux = y_list;
                Node* back = NULL;
                while(aux != NULL)
                {
                    if(aux->patient.id == patient)
                    {
                        if(back == NULL)
                        {
                            Node* temp = y_list;
                            y_list = y_list->next;
                            free(temp);
                        } else {
                            back->next = aux->next;
                            free(aux);
                        }
                        return;
                    }
                    back = aux;
                    aux = aux->next;
                }
            }
            printf("\n\tPaciente não encontrado! \n");
            break;
        case 3: // DOUTOR SILVA
            if(z_list == NULL)
            {
                printf("\n\tO Doutor %s não tem nenhum paciente no momento! \n", z->name);
            } else {
                Node* aux = z_list;
                Node* back = NULL;
                while(aux != NULL)
                {
                    if(aux->patient.id == patient)
                    {
                        if(back == NULL)
                        {
                            Node* temp = z_list;
                            z_list = z_list->next;
                            free(temp);
                        } else {
                            back->next = aux->next;
                            free(aux);
                        }
                        return;
                    }
                    back = aux;
                    aux = aux->next;
                }
            }
            printf("\n\tPaciente não encontrado! \n");
            break;
        default:
            break;
    }  
}

void enter_(char name[], int priority, int doctor)
{
    Patient* new_patient = (Patient*) malloc(sizeof(Patient));
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* init = (Node*) malloc(sizeof(Node));

    // Informações do Paciente
    strcpy(new_patient->name, name);
    new_patient->preferencial = priority;   

    switch (doctor)
    {
        case 1: // DOUTOR ESCOBAR
            if(x->patient_qtd == 15)
            {
                printf("\n\tFila de espera para o Doutor %s cheia, volte mais tarde! \n", x->name);
            } else {
                new_patient->id = x->patient_id;
                new_node->patient = *new_patient;
                x->patient_id += 1;
                x->patient_qtd++;
                if(x_list == NULL)
                {
                    x_list = new_node;
                    x_list->next = NULL;
                } else {
                    if(new_patient->preferencial == 0) // Preferencial FALSE
                    {
                        new_node->next = x_list;
                        x_list = new_node;
                    } else { // Preferencial TRUE
                        new_node->next = NULL;
                        Node* aux = x_list;
                        while (aux->next != NULL)
                        {
                            aux = aux->next;
                        }
                        aux->next = new_node;
                    }
                }
            }
            break;
        case 2: // DOUTOR OLIVEIRA
            if(y->patient_qtd == 15)
            {
                printf("\n\tFila de espera para o Doutor %s cheia, volte mais tarde! \n", y->name);
            } else {
                new_patient->id = y->patient_id;
                new_node->patient = *new_patient;
                y->patient_id += 1;
                y->patient_qtd++;
                if(y_list == NULL)
                {
                    y_list = new_node;
                    y_list->next = NULL;
                } else {
                    if(new_patient->preferencial == 0) // Preferencial FALSE
                    {
                        new_node->next = y_list;
                        y_list = new_node;
                    } else { // Preferencial TRUE
                        new_node->next = NULL;
                        Node* aux = y_list;
                        while (aux->next != NULL)
                        {
                            aux = aux->next;
                        }
                        aux->next = new_node;
                    }
                }
            }
            break;
        case 3: // DOUTOR SILVA
            if(z->patient_qtd == 15)
            {
                printf("\n\tFila de espera para o Doutor %s cheia, volte mais tarde! \n", z->name);
            } else {
                new_patient->id = z->patient_id;
                new_node->patient = *new_patient;
                z->patient_id += 1;
                z->patient_qtd++;
                if(z_list == NULL)
                {
                    z_list = new_node;
                    z_list->next = NULL;
                } else {
                    if(new_patient->preferencial == 0) // Preferencial FALSE
                    {
                        new_node->next = z_list;
                        z_list = new_node;
                    } else { // Preferencial TRUE
                        new_node->next = NULL;
                        Node* aux = z_list;
                        while (aux->next != NULL)
                        {
                            aux = aux->next;
                        }
                        aux->next = new_node;
                    }
                }
            }
            break;  
        default:
            printf("\n\tO doutor informado não existe! \n");
            return;
    }
}

int menu()
{
    int value = 0;

    printf("\nAgendamento de Consulta Médica \n");
    printf("Informe a Operação - [1]Entrar na Fila [2]Sair da Fila [3]Mostrar as Filas [4]Atendimento [0]Sair \n");
    scanf("%d", &value);

    return value;
}

int main()
{
    char name[100];
    int value = 0, priority = 0, doctor = 0, patient = 0;

    doctors_create();
    do
    {
        value = menu();
        switch (value)
        {
            case 0:
                break;
            case 1:
                // Informações do Paciente 
                printf("Informe Nome do Paciente: ");
                scanf(" %[^\n]", name);
                printf("O Paciente é Prioridade: [1]SIM [0]NÃO\n");
                scanf("%d", &priority);

                // Informações de Atendimento
                printf("Informe o Médico: ");
                printf("\n\t[1]Doutor Escobar \n\t[2]Doutor Oliveira \n\t[3]Doutor Silva \n");
                scanf("%d", &doctor);

                enter_(name, priority, doctor);
                break;
            case 2:
                // Médico
                printf("Informe o Médico: ");
                printf("\n\t[1]Doutor Escobar \n\t[2]Doutor Oliveira \n\t[3]Doutor Silva \n");
                scanf("%d", &doctor);
                list_(doctor);
                
                // Paciente
                printf("\nInforme o Número do Paciente que deseja sair da Fila: ");
                scanf("%d", &patient);
                exit_(patient, doctor);
                break;
            case 3:
                // Informações do Médico
                printf("Qual Médico você deseja ver a Lista de Espera?");
                printf("\n\t[1]Doutor Escobar \n\t[2]Doutor Oliveira \n\t[3]Doutor Silva \n");
                scanf("%d", &doctor);
                list_(doctor);
                break;
            case 4:
                // Médico
                printf("Informe o Médico: ");
                printf("\n\t[1]Doutor Escobar \n\t[2]Doutor Oliveira \n\t[3]Doutor Silva \n");
                scanf("%d", &doctor);
                service_(doctor);
                break;
            default:
                printf("Valor Inválido!");
                break;
        }

    }while(value != 0);

    return 0;
}