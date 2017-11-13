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
            int n = cin.nextInt();
            int k = cin.nextInt();
            int res = n;
            int div = 0;
            int rem = 0;
            do {
                div = n / k;
                rem = n % k;
                res += div;
                n = div + rem;
            } while (div != 0);
            System.out.println(res);
        }
    }
}