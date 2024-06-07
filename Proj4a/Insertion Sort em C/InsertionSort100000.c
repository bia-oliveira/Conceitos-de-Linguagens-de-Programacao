#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; 
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

    int arr100000[100000];

    generateRandomArray(arr100000, 100000);
  
    int n = sizeof(arr100000) / sizeof(arr100000[0]);
    insertionSort(arr100000, n);
    printArray(arr100000, n);
    return 0;
}
