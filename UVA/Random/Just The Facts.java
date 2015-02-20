import java.math.BigDecimal;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        String str;
        long number;
        char ch = 'm';
        while (cin.hasNext()) {
            number = cin.nextLong();
            str = Factorial(number).toString();
            for (int i = str.length() - 1; i >= 0; i--)
                if (str.charAt(i) != '0') {
                    ch = str.charAt(i);
                    break;
                }
            System.out.printf("%5d -> %c\n", number, ch);
        }

    }

    public static BigDecimal Factorial(long n) {
        BigDecimal toret = BigDecimal.ONE;
        for (int i = 2; i <= n; i++)
            toret = toret.multiply(new BigDecimal(Integer.toString(i)));
        return toret;
    }
}