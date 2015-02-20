import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            List<BigInteger> data = new ArrayList<BigInteger>();
            BigInteger number = in.nextBigInteger();
            BigInteger big = BigInteger.ZERO;
            while (!number.equals(BigInteger.valueOf(-999999))) {
                data.add(number);
                big = big.min(number);
                number = in.nextBigInteger();
            }
            big = big.subtract(BigInteger.valueOf(10));
            for (int i = 0; i < data.size(); ++i) {
                BigInteger product = data.get(i);
                big = big.max(product);
                for (int j = i + 1; j < data.size(); ++j) {
                    product = product.multiply(data.get(j));
                    big = big.max(product);
                }
            }
            System.out.println(big);
        }
    }
}
