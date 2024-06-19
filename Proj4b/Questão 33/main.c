#include <stdio.h>

// Função para calcular a aproximação da raiz quadrada
double sqrtApprox(double A, int n) {
    double x = 1.0; // inicializa x1 como 1

    for (int i = 0; i < n; i++) {
        x = (x + A / x) / 2.0;
    }

    return x;
}

int main() {
    double A;
    int n;

    printf("Digite o valor de A (positivo): ");
    scanf("%lf", &A);

    printf("Digite o número de iterações n (inteiro e positivo): ");
    scanf("%d", &n);

    if (A <= 0 || n <= 0) {
        printf("Valores inválidos para A ou n.\n");
    } else {
        double result = sqrtApprox(A, n);
        printf("A aproximação da raiz quadrada de %lf é: %lf\n", A, result);
    }

    return 0;
}
