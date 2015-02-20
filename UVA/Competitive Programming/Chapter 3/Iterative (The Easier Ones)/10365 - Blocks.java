import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int n = cin.nextInt();
            List<Integer> divisors = new ArrayList<Integer>();
            for (int i = 1; i * i <= n; ++i)
                if (n % i == 0) {
                    divisors.add(n / i);
                    divisors.add(i);
                }
            int size = divisors.size();
            int koko = Integer.MAX_VALUE;
            for (int a = 0; a < size; ++a)
                for (int b = 0; b < size; ++b)
                    for (int c = 0; c < size; ++c) {
                        int x = divisors.get(a);
                        int y = divisors.get(b);
                        int z = divisors.get(c);
                        if (x * y * z == n) {
                            koko = Math.min(koko, 2 * ((x * y) + (x * z) + (y * z)));
                        }
                    }
            System.out.println(koko);
        }
    }
}