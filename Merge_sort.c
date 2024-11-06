#include <stdio.h>
#include <stdlib.h>

// struct de um nó
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

// função para divisão da lista
Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    Node* temp = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
    }

    if (temp != NULL) {
        temp->next = NULL;
    }

    return slow;
}

// função de mesclagem de listas
Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// ordenação com merge sort 
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* middle = split(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(middle);

    return merge(left, right);
}

int main() {
    Node* head = NULL;
    int a;

    printf("Digite os números: \n");

    // lê números separados por espaços até encontrar EOF (end of file) que ocorre com CTRL D ou CTRL Z
    while (scanf("%d", &a) != EOF) {
        insertNode(&head, a);
    }

    mergeSort(head);
    printf("Lista ordenada: ");
    printList(head);

    return 0;
}
