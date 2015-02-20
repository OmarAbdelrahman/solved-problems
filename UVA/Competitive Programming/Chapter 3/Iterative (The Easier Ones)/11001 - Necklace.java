import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int vtotal = cin.nextInt();
            int v0 = cin.nextInt();
            if (vtotal == 0 && v0 == 0)
                break;
            double max = Double.MIN_VALUE;
            int res = 0;
            for (int parts = 1; parts <= vtotal; ++parts) {
                double size = (double) vtotal / parts;
                if (size > (double) v0) {
                    double d = 0.3 * Math.sqrt(size - v0);
                    double curLen = d * parts;
                    if (Math.abs(max - curLen) <= 1e-9) {
                        res = 0;
                    } else if (curLen > max) {
                        max = curLen;
                        res = parts;
                    }
                }
            }
            if (max == Double.MIN_VALUE)
                System.out.println(0);
            else
                System.out.println(res);
        }
    }
}