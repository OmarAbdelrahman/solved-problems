import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.*;

public class Main {
    private static void debug(Object...os) {
        out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            long n = cin.nextLong();
            if (n == 0) break;
            long x = (long) Math.ceil(Math.sqrt(n));
            if (x % 2 == 0) {
                if (x * x - n < x)
                    out.printf("%d %d\n", x, x * x - n + 1);
                else
                    out.printf("%d %d\n", n - ((x - 1) * (x - 1)), x);
            } else {
                if (x * x - n < x)
                    out.printf("%d %d\n", x * x - n + 1, x);
                else
                    out.printf("%d %d\n", x, n - ((x - 1) * (x - 1)));
            }
        }
    }
}