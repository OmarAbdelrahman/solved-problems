import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] price;
    static int[] favor;
    static int[][] dp;
    static int money, items;

    static final int REFUND = 200;
    static final int INF = 200000000;

    public static int solve(int indx, int total) {
        if (indx == price.length) {
            int diff = money + REFUND - total;
            if (diff > money && diff <= 2000)
                return -INF;
            return 0;
        }
        if (dp[total][indx] != -1)
            return dp[total][indx];
        dp[total][indx] = solve(indx + 1, total);
        if (total - price[indx] >= 0)
            dp[total][indx] = Math.max(dp[total][indx], solve(indx + 1, total - price[indx]) + favor[indx]);
        return dp[total][indx];
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner cin = new Scanner(new File("C:\\Users\\Sebres\\IdeaProjects\\TopCoder\\src\\in.txt"));
        while (cin.hasNext()) {
            money = cin.nextInt();
            items = cin.nextInt();
            price = new int[items];
            favor = new int[items];
            for (int i = 0; i < items; ++i) {
                price[i] = cin.nextInt();
                favor[i] = cin.nextInt();
            }
            dp = new int[money + REFUND + 1][items];
            ArrayUtilis.fill(dp, -1);
            System.out.println(solve(0, money + REFUND));
        }
    }
}

class ArrayUtilis {
    public static void fill(int[] array, int val) {
        Arrays.fill(array, val);
    }

    public static void fill(int[][] array, int val) {
        for (int[] row : array) ArrayUtilis.fill(row, val);
    }

    public static void fill(int[][][] array, int val) {
        for (int[][] row2D : array) ArrayUtilis.fill(row2D, val);
    }

    public static void fill(int[][][][] array, int val) {
        for (int[][][] row3D : array) ArrayUtilis.fill(row3D, val);
    }

    public static void fill(int[][][][][] array, int val) {
        for (int[][][][] row4D : array) ArrayUtilis.fill(row4D, val);
    }
}
