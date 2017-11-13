import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int K = cin.nextInt();
        long[][] comb = new long[75][75];
        for (int i = 0; i < comb.length; i++)
            comb[i][0] = comb[i][i] = 1;
        for (int i = 1; i < comb.length; i++)
            for (int j = 1; j < i; j++)
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        while (K-- != 0) {
            int N = cin.nextInt();
            int T = cin.nextInt();
            int P = cin.nextInt();
            int extraMarks = T - (N * P);
            out.println(comb[extraMarks + N - 1][N - 1]);
        }
    }
}