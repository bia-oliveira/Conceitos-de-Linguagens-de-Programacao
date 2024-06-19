import java.util.Scanner;

public class Main {

    public static double calculatePi(int numTerms) {
        if (numTerms <= 0) {
            return Double.NaN; // Retorna NaN se o número de termos for inválido
        }

        double pi = 0.0;
        int sign = 1; // Variável para alternar o sinal dos termos

        for (int i = 0; i < numTerms; i++) {
            int denominator = 2 * i + 1;
            pi += sign * 4.0 / denominator;
            sign = -sign; // Alterna o sinal para o próximo termo
        }

        return pi;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o número de termos para calcular π: ");
        int numTerms = scanner.nextInt();

        double result = calculatePi(numTerms);

        if (Double.isNaN(result)) {
            System.out.println("Número de termos inválido.");
        } else {
            System.out.println("O valor aproximado de π com " + numTerms + " termos é: " + result);
        }

        scanner.close();
    }
}
