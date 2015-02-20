import java.math.BigInteger;
import java.util.*;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger[] factorial = new BigInteger[101];
        factorial[1] = BigInteger.valueOf(1);
        for (int i = 2; i < factorial.length; ++i)
            factorial[i] = factorial[i - 1].multiply(BigInteger.valueOf(i));
        int TC = cin.nextInt();
        while (TC-- > 0) {
            out.println(factorial[cin.nextInt()]);
        }
    }
}