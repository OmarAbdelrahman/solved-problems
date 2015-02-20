import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

	// top, bottom, front, left, back, right
    static int[][] rotation = {
        {0, 1, 2, 3, 4, 5},
        {0, 1, 3, 4, 5, 2},
        {0, 1, 5, 2, 3, 4},
        {0, 1, 4, 5, 2, 3},
        {1, 0, 4, 3, 2, 5},
        {1, 0, 3, 2, 5, 4},
        {1, 0, 2, 5, 4, 3},
        {1, 0, 5, 4, 3, 2},
        {4, 2, 0, 3, 1, 5},
        {4, 2, 3, 1, 5, 0},
        {4, 2, 1, 5, 0, 3},
        {4, 2, 5, 0, 3, 1},
        {2, 4, 1, 3, 0, 5},
        {2, 4, 3, 0, 5, 1},
        {2, 4, 0, 5, 1, 3},
        {2, 4, 5, 1, 3, 0},
        {5, 3, 2, 0, 4, 1},
        {5, 3, 0, 4, 1, 2},
        {5, 3, 4, 1, 2, 0},
        {5, 3, 1, 2, 0, 4},
        {3, 5, 2, 1, 4, 0},
        {3, 5, 1, 4, 0, 2},
        {3, 5, 4, 0, 2, 1},
        {3, 5, 0, 2, 1, 4}
    };

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        cin.nextLine();
        while (T-- != 0) {
            char[] src = cin.next().toCharArray();
            char[] trg = cin.next().toCharArray();
            System.out.println(solve(src, trg) ? "Equal" : "Not Equal");
        }
    }

    private static boolean solve(char[] src, char[] trg) {
        char[] koko = new char[6];
        for (int i = 0; i < rotation.length; ++i) {
            for (int j = 0; j < 6; ++j)
                koko[j] = src[rotation[i][j]];
            if (equal(koko, trg)) return true;
        }
        return false;
    }

    private static boolean equal(char[] src, char[] trg) {
        for (int i = 0; i < 6; ++i)
            if (src[i] != trg[i]) return false;
        return true;
    }
}