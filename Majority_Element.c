#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void insertionSort ( int list [], int x ) {

	for (int i = 1; i < x ; i ++) {

		int key = list [ i ];

		int j = i - 1;

		while ( j >= 0 && list [ j ] > key ) {

			list [ j + 1] = list [ j ];

			j = j - 1;

		}
		list [ j + 1] = key;

	}

}

void printList(int list[], int size){
	for (int i= 0; i<size; i++ ){
		printf("%d ", list[i]);
		
	}printf("\n");
}
void  MajorityElement (int list[], int capacity){
	int middle = capacity/2;
	cout<< list[middle] << endl;
}

int main() {
    int *list = NULL;
    int size = 0;
    int capacity = 1;
    int input;
    list = (int*) malloc(capacity * sizeof(int));

//leitura até um "end of file" indicado por CTRL D ou CTRL Z
    while (scanf("%d", &input) != EOF) {
        if (size == capacity) {
            capacity += 1;
            list = (int*) realloc(list, capacity * sizeof(int));
        }
        list[size++] = input;
    }
insertionSort(list, capacity);
MajorityElement(list, capacity);
 
free(list);
return 0;
}
	
