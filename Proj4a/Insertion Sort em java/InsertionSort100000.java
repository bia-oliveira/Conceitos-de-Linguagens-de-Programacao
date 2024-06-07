//vetor de 100000 elementos

import java.util.Random;

public class InsertionSort100000 {

    public static void generateRandomArray(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(100000); 
        }
    }
    
    void insertionSort(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        InsertionSort100000 ob = new InsertionSort100000();
        
        int[] arr100000 = new int[100000];

        generateRandomArray(arr100000);
        ob.insertionSort(arr100000);
        ob.printArray(arr100000);
    }
}
