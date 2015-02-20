import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static double[] prob = {
        12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15, 6.71, 8.68,
        2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52
    };
    static int[] taken = new int[26];
    static char[][] choice = {
        {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'},
        {'a', 'e', 'i', 'o', 'u'}
    };
    static int wordsCnt;
    static double allSPC;
    static String word;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        cin.nextLine();
        while (T-- != 0) {
            word = cin.nextLine();
            wordsCnt = 0;
            allSPC = 0.0;
            double wordSBC = SBC(word);
            Arrays.fill(taken, 0);
            ++taken[word.charAt(0) - 'a'];
            generate(1, prob[word.charAt(0) - 'a']);
            double avg = allSPC / wordsCnt;
            System.out.println(wordSBC < avg ? "below" : "above or equal");
        }
    }

    private static void generate(int depth, double sbc) {
        if (depth == word.length()) {
            allSPC += sbc;
            ++wordsCnt;
        } else {
            int i = depth % 2;
            for (int j = 0; j < choice[i].length; ++j) {
                int curIndex = choice[i][j] - 'a';
                if (taken[curIndex] < 2) {
                    ++taken[curIndex];
                    generate(depth + 1, sbc + ((depth + 1) * prob[curIndex]));
                    --taken[curIndex];
                }
            }
        }
    }

    private static double SBC(String word) {
        double res = 0;
        for (int i = 0; i < word.length(); ++i)
            res += ((i + 1) * prob[word.charAt(i) - 'a']);
        return res;
    }
}