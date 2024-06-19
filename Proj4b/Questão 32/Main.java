import java.util.Scanner;

public class Main {

    // Método principal para calcular e^x usando a série de Taylor
    public static Double calculateExponential(double x, int n) {
        if (n < 0) {
            return null; // Se n for inválido, retorna null
        }

        double result = 0.0;

        for (int i = 0; i <= n; i++) {
            result += Math.pow(x, i) / factorial(i);
        }

        return result;
    }

    // Método para calcular o fatorial de um número
    public static long factorial(int num) {
        if (num == 0) {
            return 1;
        }
        long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }

    // Método principal para executar o programa
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicita o valor de x ao usuário
        System.out.print("Digite o valor de x: ");
        double x = scanner.nextDouble();

        // Solicita o valor de n ao usuário
        System.out.print("Digite o valor de n (inteiro e positivo): ");
        int n = scanner.nextInt();

        // Calcula o valor de e^x
        Double result = calculateExponential(x, n);

        // Exibe o resultado ou uma mensagem de erro
        if (result == null) {
            System.out.println("Valor inválido para n.");
        } else {
            System.out.println("O valor de e^" + x + " é: " + result);
        }

        scanner.close();
    }
}
