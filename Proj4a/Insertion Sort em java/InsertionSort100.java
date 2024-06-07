//vetor de 10 elementos

import java.util.Random;

public class InsertionSort100 {

    public static void generateRandomArray(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(1000); 
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
        InsertionSort100 ob = new InsertionSort100();
        
        int[] arr100 = new int[100];

        generateRandomArray(arr100);
        ob.insertionSort(arr100);
        ob.printArray(arr100);
    }
}
