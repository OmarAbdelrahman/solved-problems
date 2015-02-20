import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner cin = new Scanner(new File("C:\\Users\\Sebres\\IdeaProjects\\SRM\\src\\in.txt"));
        int T = cin.nextInt();
        while (T-- != 0) {
            BigInteger n = cin.nextBigInteger();
            BigInteger minusOne = n.subtract(BigInteger.valueOf(1));
            BigInteger minusTwo = n.subtract(BigInteger.valueOf(2));
            BigInteger minusThree = n.subtract(BigInteger.valueOf(3));
            BigInteger nc4 = n.multiply(minusOne).multiply(minusTwo).multiply(minusThree);
            nc4 = nc4.divide(BigInteger.valueOf(24));
            BigInteger nc2 = n.multiply(minusOne);
            nc2 = nc2.divide(BigInteger.valueOf(2));
            out.println(nc4.add(nc2).add(BigInteger.ONE));
        }
    }

    private static void debug(Object...os) {
        out.println(Arrays.deepToString(os));
    }
}