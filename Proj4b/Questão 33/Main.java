import java.util.Scanner;

public class Main {

    public static double sqrtApprox(double A, int n) {
        double x = 1.0; // inicializa x1 como 1

        for (int i = 0; i < n; i++) {
            x = (x + A / x) / 2.0;
        }

        return x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o valor de A (positivo): ");
        double A = scanner.nextDouble();

        System.out.print("Digite o número de iterações n (inteiro e positivo): ");
        int n = scanner.nextInt();

        if (A <= 0 || n <= 0) {
            System.out.println("Valores inválidos para A ou n.");
        } else {
            double result = sqrtApprox(A, n);
            System.out.println("A aproximação da raiz quadrada de " + A + " é: " + result);
        }

        scanner.close();
    }
}
