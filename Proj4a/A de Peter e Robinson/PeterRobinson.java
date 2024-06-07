public class PeterRobinson {

    // Função A de Peter e Robinson
    public static int A(int m, int n) {
        if (m == 0) return n + 1;
        if (n == 0) return A(m - 1, 1);
        return A(m - 1, A(m, n - 1));
    }

    public static void main(String[] args) {

        // Testando a função A de Peter e Robinson
        System.out.println("A(3, 15) = " + A(3, 12));
    }
}
