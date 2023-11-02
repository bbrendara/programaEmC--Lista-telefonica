#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

struct Contact {
    char name[50];
    char phone[20];
    struct Contact* next;
};

struct Contact* createContact(const char* name, const char* phone) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    if (newContact) {
        strcpy(newContact->name, name);
        strcpy(newContact->phone, phone);
        newContact->next = NULL;
    }
    return newContact;
}

void addContact(struct Contact** list, const char* name, const char* phone) {
    struct Contact* newContact = createContact(name, phone);
    if (newContact) {
        newContact->next = *list;
        *list = newContact;
    }
}

void displayContacts(const struct Contact* list) {
    const struct Contact* current = list;
    int count = 0; // Variável para contar contatos

    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n\n", current->phone);
        current = current->next;
        count++;
    }

    printf("Total de contatos: %d\n\n\n\n", count); // Exibe a quantidade de contatos
}

void deleteContact(struct Contact** list, const char* name) {
    struct Contact* current = *list;
    struct Contact* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Contato não encontrado.\n");
}

void updateContact(struct Contact* list, const char* name, const char* newPhone) {
    while (list != NULL) {
        if (strcmp(list->name, name) == 0) {
            strcpy(list->phone, newPhone);
            
            return;
        }
        list = list->next;
    }

    printf("Contato não encontrado.\n");
}

int main() {
    struct Contact* contactList = NULL;
    char name[50];
    char phone[20];
    int choice;
    int schoice;
    int segundos = 1;

    while (1) {
        printf("Gerenciamento de Contatos:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Exibir Contatos\n");
        printf("3. Excluir Contato\n");
        printf("4. Atualizar Contato\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
            	printf("*NOVO CONTATO*:\n\n");
                printf(" Nome: ");
                scanf("%s", name);
                printf(" Telefone: ");
                scanf("%s", phone);
                addContact(&contactList, name, phone);
                system("cls");
                printf("Contato adicionado com sucesso!\n AGUARDE...");
                sleep(segundos);
                system("cls");
                sleep(segundos);
                break;
            case 2:
            	system("cls");
            	printf ("*MEUS CONTATOS* \n\n");
                displayContacts(contactList);
                printf("Digite 1 e enter para retornar ao menu\n");
                scanf("%d", &schoice);
                
                switch (schoice) {
                	case 1:
                		system("cls");
                		break;
                	default:
                		system("cls");
                        break;  
				} break;
                
            case 3:
            	system("cls");
            	printf("*EXCLUIR CONTATO*: \n\n");
                printf(" Nome do contato a ser excluido: ");
                scanf("%s", name);
                deleteContact(&contactList, name);
                system("cls");
            	printf("Aguarde...");
            	sleep(segundos);
            	system("cls");
            	printf("Contato excluido com sucesso!\n\n\n Retornando ao menu...");
            	sleep(segundos);
            	system("cls");
            	
                break;
            case 4:
            	system("cls");
            	printf("*EDITAR CONTATO*: \n\n");
                printf(" Nome do contato a ser atualizado: ");
                scanf("%s", name);
                printf(" Novo numero de telefone: ");
                scanf("%s", phone);
                updateContact(contactList, name, phone);
                system("cls");
            	printf("Aguarde...");
            	sleep(segundos);
            	system("cls");
            	printf("Contato atualizado com sucesso!\n");
            	sleep(segundos);
            	system("cls");
                break;
            case 5:
            	system("cls");
            	printf("Encerrando programa... ");
            	sleep(segundos);
            	system("cls");
            	printf("Aguarde...");
            	sleep(segundos);
            	system("cls");
                // Liberar a memória alocada antes de sair
                while (contactList) {
                    struct Contact* temp = contactList;
                    contactList = contactList->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}

