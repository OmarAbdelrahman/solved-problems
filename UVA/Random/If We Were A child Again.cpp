import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        BigInteger first;
        BigInteger second;
        String operation;

        while (cin.hasNext()) {
            first = cin.nextBigInteger();
            operation = cin.next();
            second = cin.nextBigInteger();

            if (operation.trim().equals("%")) {
                System.out.println(first.mod(second));
            } else if (operation.trim().equals("/")) {
                System.out.println(first.divide(second));
            }
        }
    }
}