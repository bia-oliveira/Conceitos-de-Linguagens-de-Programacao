public class Ackermann {

    // Função phi de Ackermann
    public static int ackermannPhi(int m, int n, int p) {
        if (p == 0) return m + n;
        if (n == 0 && p == 1) return 0;
        if (n == 0 && p == 2) return m;
        if (p > 2) return p;
        if (n > 0 && p > 0) return ackermannPhi(m, ackermannPhi(m, n - 1, p), p - 1);
        return 0; // para casos não cobertos (deve-se evitar alcançar aqui)
    }

    public static void main(String[] args) {
        // Testando a função φ de Ackermann
        System.out.println("ackermannPhi(2, 3, 0) = " + ackermannPhi(2, 3, 0));
    }
}
