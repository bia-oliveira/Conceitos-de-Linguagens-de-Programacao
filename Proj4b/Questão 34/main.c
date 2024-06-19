#include <stdio.h>
#include <math.h>

double calculatePi(int numTerms) {
    if (numTerms <= 0) {
        return NAN; // Retorna NaN se o número de termos for inválido
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

int main() {
    int numTerms;

    printf("Digite o número de termos para calcular π: ");
    scanf("%d", &numTerms);

    double result = calculatePi(numTerms);

    if (isnan(result)) {
        printf("Número de termos inválido.\n");
    } else {
        printf("O valor aproximado de π com %d termos é: %f\n", numTerms, result);
    }

    return 0;
}
