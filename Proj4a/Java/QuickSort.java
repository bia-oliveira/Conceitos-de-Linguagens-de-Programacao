import java.util.Random;

public class QuickSort {

    public static void generateRandomArray(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(100000); 
        }
    }
    
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

    void sort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        QuickSort ob = new QuickSort();

        int[] arr10 = new int[10];
        int[] arr100 = new int[100];
        int[] arr1000 = new int[1000];
        int[] arr10000 = new int[10000];
        int[] arr100000 = new int[100000];

        generateRandomArray(arr100000);
        int n = arr100000.length;
        
        ob.sort(arr100000, 0, n - 1);
        printArray(arr100000);
    }
}
