#include <stdio.h>

// Função phi de Ackermann
int ackermann_phi(int m, int n, int p) {
    if (p == 0) return m + n;
    if (n == 0 && p == 1) return 0;
    if (n == 0 && p == 2) return m;
    if (p > 2) return p;
    if (n > 0 && p > 0) return ackermann_phi(m, ackermann_phi(m, n-1, p), p-1);
    return 0; // para casos não cobertos (deve-se evitar alcançar aqui)
}

int main() {
    // Testando a função φ de Ackermann
    printf("ackermann_phi(1, 3, 0) = %d\n", ackermann_phi(1, 3, 0));

    return 0;
}
