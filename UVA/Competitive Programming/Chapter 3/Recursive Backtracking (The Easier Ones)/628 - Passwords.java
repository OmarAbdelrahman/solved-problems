import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static int[] comb;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            System.out.println("--");
            int nWords = cin.nextInt();
            cin.nextLine();
            String[] words = new String[nWords];
            for (int i = 0; i < nWords; ++i)
                words[i] = cin.nextLine();
            int nRules = cin.nextInt();
            cin.nextLine();
            for (int i = 0; i < nRules; ++i) {
                String rule = cin.nextLine();
                int cnt = 0;
                for (int j = 0; j < rule.length(); ++j)
                    if (rule.charAt(j) == '0') ++cnt;
                comb = new int[cnt];
                for (int j = 0; j < words.length; ++j)
                    doIt(words[j], rule, 0);
            }
        }
    }

    private static void doIt(String word, String rule, int depth) {
        if (depth == comb.length) {
            String koko = "";
            for (int i = 0, indx = 0; i < rule.length(); ++i)
                if (rule.charAt(i) == '0')
                    koko += comb[indx++];
                else
                    koko += word;
            System.out.println(koko);
        } else for (int i = 0; i < 10; ++i) {
            comb[depth] = i;
            doIt(word, rule, depth + 1);
        }
    }
}