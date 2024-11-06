#include <stdio.h>
#include <stdlib.h>

// struct de nó de lista duplamente encadeada
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// criação de nó
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
        newNode->prev = current;
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

// swap de dados (troca) de dois nós
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// retorna o último nó
Node* getLastNode(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

// função de divisão da lista
Node* partition(Node* low, Node* high) {
    int pivo = high->data; 
    Node* i = low->prev; 

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivo) {
            if (i == NULL) {
                i = low;
            } else {
                i = i->next;
            }
            swap(i, j);
        }
    }

    if (i == NULL) {
        i = low;
    } else {
        i = i->next;
    }
    swap(i, high);
    return i;
}

//quick sort recursivo
void quickSort(Node* low, Node* high) {
    if (high != NULL && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

int main() {
    Node* head = NULL;
    int a;

    printf("Digite os números: \n");

    // Lê números separados por espaços até encontrar EOF (end of file) que ocorre com CTRL D ou CTRL Z
    while (scanf("%d", &a) != EOF) {
        insertNode(&head, a);
    }

    Node* last = getLastNode(head);
    quickSort(head, last);
    printf("Lista ordenada: ");
    printList(head);

    return 0;
}
