#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    srand(time(0)); // Inicializa o gerador de números aleatórios

    int arr10000[10000];

    generateRandomArray(arr10000, 10000);
  
    int n = sizeof(arr10000) / sizeof(arr10000[0]);
    insertionSort(arr10000, n);
    printArray(arr10000, n);
    return 0;
}
