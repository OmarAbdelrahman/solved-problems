import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int MAX = 30000 + 1;
    static final int[] coins = {1, 5, 10, 25, 50};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long[] ways = new long[MAX];
        ways[0] = 1;
        for (int i = 0; i < coins.length; ++i)
            for (int j = coins[i]; j < MAX; ++j)
                if (j - coins[i] >= 0)
                    ways[j] += ways[j - coins[i]];
        while (cin.hasNext()) {
            int n = cin.nextInt();
            long res = ways[n];
            if (res == 1)
                System.out.printf("There is only 1 way to produce %d cents change.\n", n);
            else
                System.out.printf("There are %d ways to produce %d cents change.\n", res, n);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}