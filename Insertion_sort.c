#include <stdio.h>
#include <stdlib.h>

// struct de lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// criação de nó
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// inserção de nó
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// impressão
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ordenação com insertion sort
void insertionSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            // insere no início
            current->next = sorted;
            sorted = current;
        } else {
            // localiza o ponto de inserção
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

int main() {
    Node* head = NULL;
    int a;

    printf("Digite os números: \n");

    // lê os números separados por espaços até encontrar EOF (end of file) que ocorre com CTRL D ou CTRL Z
    while (scanf("%d", &a) != EOF) {
        insertNode(&head, a);
    }
    
    insertionSort(&head);
    printf("Lista ordenada: ");
    printList(head);

    return 0;
}
