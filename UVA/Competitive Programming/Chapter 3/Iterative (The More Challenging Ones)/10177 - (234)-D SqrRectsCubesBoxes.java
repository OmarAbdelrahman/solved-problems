import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    final static int MAX = 101;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long[] s2 = new long[MAX];
        long[] r2 = new long[MAX];
        long[] s3 = new long[MAX];
        long[] r3 = new long[MAX];
        long[] s4 = new long[MAX];
        long[] r4 = new long[MAX];
        for (int i = 1; i < MAX; ++i) {
            s2[i] = s2[i - 1] + (i * i);
            s3[i] = s3[i - 1] + (i * i * i);
            s4[i] = s4[i - 1] + (i * i * i * i);
            r2[i] = r2[i - 1] + (i * i * (i - 1));
            r3[i] = (long) (Math.pow((i * (i + 1)) / 2, 3.0)) - s3[i];
            r4[i] = (long) (Math.pow((i * (i + 1)) / 2, 4.0)) - s4[i];
        }
        while (cin.hasNext()) {
            int N = cin.nextInt();
            System.out.printf("%d %d %d %d %d %d\n", s2[N], r2[N], s3[N], r3[N], s4[N], r4[N]);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}