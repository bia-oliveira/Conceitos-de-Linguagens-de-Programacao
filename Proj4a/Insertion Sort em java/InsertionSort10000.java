//vetor de 10000 elementos

import java.util.Random;

public class InsertionSort10000 {

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
        InsertionSort10000 ob = new InsertionSort10000();
        
        int[] arr10000 = new int[10000];

        generateRandomArray(arr10000);
        ob.insertionSort(arr10000);
        ob.printArray(arr10000);
    }
}
