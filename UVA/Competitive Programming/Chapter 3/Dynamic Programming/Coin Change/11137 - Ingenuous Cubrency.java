import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int MAX = 10000;
    static int[] coins = new int[22];

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        for (int i = 0; i < coins.length; ++i)
            coins[i] = i * i * i;
        long[] ways = new long[MAX];
        ways[0] = 1;
        for (int i = 1; i < coins.length; ++i)
            for (int val = coins[i]; val < MAX; ++val)
                if (val - coins[i] >= 0)
                    ways[val] += ways[val - coins[i]];
        while (cin.hasNext())
            System.out.println(ways[cin.nextInt()]);
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}