#include <stdio.h>

// Função A de Peter e Robinson
int A(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return A(m-1, 1);
    return A(m-1, A(m, n-1));
}

int main() {

    // Testando a função A de Peter e Robinson
    printf("A(3, 15) = %d\n", A(3, 15));

    return 0;
}
