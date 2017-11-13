import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        for (int c = 1; cases-- != 0; ++c) {
            Map<Character, Integer> cost = new HashMap<Character, Integer>();
            for (int i = 0; i < 36; ++i)
                cost.put(digits.charAt(i), cin.nextInt());
            System.out.printf("Case %d:\n", c);
            int n = cin.nextInt();
            for (int i = 0; i < n; ++i) {
                int small = Integer.MAX_VALUE;
                int decimal = cin.nextInt();
                int[] baseValue = new int[36];
                for (int toBase = 2; toBase <= 36; ++toBase) {
                    String resultBase = convert(decimal, toBase);
                    int koko = 0;
                    for (int j = 0; j < resultBase.length(); ++j)
                        koko += cost.get(resultBase.charAt(j)).intValue();
                    small = Math.min(small, koko);
                    baseValue[toBase - 1] = koko;
                }
                System.out.printf("Cheapest base(s) for number %d:", decimal);
                for (int j = 1; j < 36; ++j)
                    if (baseValue[j] == small)
                        System.out.printf(" %d", j + 1);
                System.out.println();
            }
            if (cases != 0) System.out.println();
        }
    }

    private static String convert(int decimal, int toBase) {
        StringBuilder number = new StringBuilder();
        while (decimal > 0) {
            if (decimal % toBase > 9)
                number.append((char) (((decimal % toBase) + '0') - '9' + 'A' - 1));
            else
                number.append(decimal % toBase);
            decimal /= toBase;
        }
        return number.reverse().toString();
    }
}