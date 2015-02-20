import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    static int[][][] memo;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        for (int turn = 1; cin.hasNext(); turn++) {
            int L = cin.nextInt();
            int S = cin.nextInt();
            if (L == 0 && S == 0)
                break;
            memo = new int[30][30][S + 1];
            for (int[][] a : memo) for (int[] b : a) Arrays.fill(b, -1);
            out.printf("Case %d: %d\n", turn, solve(0, 0, 0, L, S));
        }
    }

    private static int solve(int curLength, int last, int sum, int L, int S) {
        if (sum > S || curLength >= 30)
            return 0;
        if (curLength == L)
            return sum == S ? 1 : 0;
        if (memo[curLength][last][sum] != -1)
            return memo[curLength][last][sum];
        memo[curLength][last][sum] = 0;
        for (int i = last + 1; i <= 26; i++)
            memo[curLength][last][sum] += solve(curLength + 1, i, sum + i, L, S);
        return memo[curLength][last][sum];
    }
}