import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int MAX = 7489 + 1;
    static final int[] coins = {1, 5, 10, 25, 50};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int[] ways = new int[MAX];
        ways[0] = 1;
        for (int i = 0; i < coins.length; ++i)
            for (int j = coins[i]; j < MAX; ++j)
                if (j - coins[i] >= 0)
                    ways[j] += ways[j - coins[i]];
        while (cin.hasNext())
            System.out.println(ways[cin.nextInt()]);
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}