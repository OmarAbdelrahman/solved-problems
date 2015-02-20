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
        for (int c = 1; cin.hasNext(); ++c) {
            int n = cin.nextInt();
            if (n == 0) break;
            int[] data = new int[n];
            for (int i = 0; i < n; ++i) data[i] = cin.nextInt();
            int m = cin.nextInt();
            System.out.printf("Case %d:\n", c);
            for (int i = 0; i < m; ++i) {
                int target = cin.nextInt();
                int minDiff = Integer.MAX_VALUE;
                int koko = 0;
                for (int a = 0; a < n; ++a)
                    for (int b = a + 1; b < n; ++b) {
                        int sum = data[a] + data[b];
                        if (Math.abs(sum - target) < minDiff) {
                            minDiff = Math.abs(sum - target);
                            koko = sum;
                        }
                    }
                System.out.printf("Closest sum to %d is %d.\n", target, koko);
            }
        }
    }
}