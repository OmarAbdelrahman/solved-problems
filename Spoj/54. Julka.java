import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            BigInteger x = cin.nextBigInteger();
            BigInteger y = cin.nextBigInteger();
            BigInteger b = x.add(y);
            b = b.divide(BigInteger.valueOf(2));
            out.println(b);
            out.println(b.subtract(y));
        }
    }
}