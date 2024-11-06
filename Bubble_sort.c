#include <stdio.h>
#include <stdlib.h>

// struct e funções da lista:
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//criação de nó
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//inserção de nó
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
    printf("\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf( "\n"); 
}

// ordenação com bubble sort
void bubbleSort(Node** head) {
    Node* currentNode;
    int swap;
    int temp;

    if (*head == NULL)
        return;

    do {
        swap = 0;
        currentNode = *head;

        while (currentNode->next != NULL) {
            if (currentNode->data > currentNode->next->data){
                
                temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
                swap = 1;
            }
            currentNode = currentNode->next;
        }
    } while (swap);
}


int main() { 
	//criação de uma lista com input como nós
	Node* head = NULL;
	int a; 
	
	printf("Digite os números: \n");
	//lê números separados por espaços até encontrar EOF(end of file) que ocorre com CTRL D ou CTRL Z:
	while (scanf("%d", &a) != EOF) { 
			insertNode(&head, a); 
	}
																							
  bubbleSort(&head);
	printf("Lista ordenada: "); 
	printList(head);  
	return 0;	
}
