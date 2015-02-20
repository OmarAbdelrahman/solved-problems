import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

	static int[] stick;
    static int[][] memo;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int stickLen = cin.nextInt();
            if (stickLen == 0) break;
            int cuts = cin.nextInt();
            stick = new int[cuts + 2];
            stick[0] = 0;
            stick[cuts + 1] = stickLen;
            for (int i = 1; i < cuts + 1; ++i)
                stick[i] = cin.nextInt();
            int n = stick.length;
            memo = new int[n][n];
            for (int[] row : memo) Arrays.fill(row, -1);
            System.out.printf("The minimum cutting is %d.\n", solve(0, n - 1));
        }
    }

    private static int solve(int left, int right) {
        if (left + 1 == right)
            return memo[left][right] = 0;
        if (memo[left][right] != -1)
            return memo[left][right];
        memo[left][right] = Integer.MAX_VALUE;
        for (int cut = left + 1; cut < right; ++cut)
            memo[left][right] = Math.min(memo[left][right], solve(left, cut) + solve(cut, right) + (stick[right] - stick[left]));
        return memo[left][right];
    }
}