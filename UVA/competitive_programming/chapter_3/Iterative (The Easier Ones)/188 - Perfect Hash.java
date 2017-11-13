import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String line = cin.nextLine();
            String[] parts = line.split(" ");
            int n = 0;
            for (String word : parts) if (word.length() > 0) ++n;
            int[] wordVal = new int[n];
            int index = 0;
            for (int i = 0; i < parts.length; ++i)
                if (parts[i].length() > 0)
                    wordVal[index++] = getValue(parts[i]);
            Arrays.sort(wordVal);
            int C = wordVal[0];
            while (true) {
                boolean flag = false;
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j)
                        if ((C / wordVal[i]) % n == (C / wordVal[j]) % n) {
                            flag = true;
                            C = Math.min((C / wordVal[i] + 1) * wordVal[i], (C / wordVal[j] + 1) * wordVal[j]);
                            break;
                        }
                    if (flag) break;
                }
                if (!flag) break;
            }
            System.out.printf("%s\n%d\n\n", line, C);
        }
    }

    private static int getValue(String part) {
        int res = 0;
        for (int i = 0; i < part.length(); ++i)
            res = (res << 5) + (part.charAt(i) - 'a' + 1);
        return res;
    }
}