#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; 
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
  
  srand(time(0)); // Inicializa o gerador de números aleatórios

  int arr10[10];
  int arr100[100];
  int arr1000[1000];
  int arr10000[100000];
  int arr100000[100000];
  int arr1000000[1000000];

  generateRandomArray(arr100000, 100000);
  int n = sizeof(arr100000) / sizeof(arr100000[0]);
  bubbleSort(arr100000, n);
  printArray(arr100000, n);
  
  return 0;
}
