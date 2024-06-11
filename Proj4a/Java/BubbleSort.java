import java.util.Random;

public class BubbleSort {

    public static void generateRandomArray(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(100000); 
        }
    }
    
    void bubbleSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        BubbleSort ob = new BubbleSort();

        int[] arr10 = new int[10];
        int[] arr100 = new int[100];
        int[] arr1000 = new int[1000];
        int[] arr10000 = new int[10000];
        int[] arr100000 = new int[100000];

        generateRandomArray(arr100000);

        ob.bubbleSort(arr100000);
        ob.printArray(arr100000);
    }
}
