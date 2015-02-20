import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        long number;
        while (cin.hasNext()) {
            number = cin.nextLong();
            if (number < 0) break;
            factor(number);
        }
    }

    public static void factor(long n) {
        for (long i = 2; i <= (long)Math.sqrt((double)n); i++) {
            while (n % i == 0) {
                System.out.printf("    %d\n", i);
                n /= i;
            }
        }
        if (n > 1) System.out.printf("    %d\n", n);
        System.out.println();
    }
}