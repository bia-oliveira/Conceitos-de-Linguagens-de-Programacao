#include <stdio.h>

// Função para calcular o fatorial de um número
unsigned long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        unsigned long long fact = 1;
        for (int i = 2; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }
}

// Função para calcular e^x usando a série de Taylor
double calculate_ex(double x, int n) {
    double result = 0.0;

    for (int i = 0; i <= n; i++) {
        result += (pow(x, i) / factorial(i));
    }

    return result;
}

// Função principal
int main() {
    double x;
    int n;

    // Ler o valor de x
    printf("Digite o valor de x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Valor de x inválido.\n");
        return 1;
    }

    // Ler o valor de n
    printf("Digite o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Valor de n inválido.\n");
        return 1;
    }

    // Calcular e^x
    double result = calculate_ex(x, n);

    // Exibir o resultado
    printf("O valor de e^%.2f com n=%d é: %f\n", x, n, result);

    return 0;
}
