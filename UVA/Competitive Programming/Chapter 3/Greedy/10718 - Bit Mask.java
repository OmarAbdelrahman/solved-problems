import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            long N = cin.nextLong();
            long L = cin.nextLong();
            long U = cin.nextLong();
            long M = 0;
            long best = Long.MAX_VALUE;
            for (long p = 31; p >= 0; --p) {
                long nowM = M | (1L << p);
                if (nowM > U) continue;
                if (nowM <= L) {
                    M = nowM;
                    if (M < best)
                        best = M;
                } else if (nowM <= U && nowM >= L) {
                    if ((M | N) == (nowM | N)) {
                        if (M < best) best = M;
                    } else {
                        M = nowM;
                        best = M;
                    }
                }
            }
            System.out.println(M);
        }
    }
}