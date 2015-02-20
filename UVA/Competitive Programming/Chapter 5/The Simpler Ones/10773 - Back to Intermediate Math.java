import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        for  (int c = 1; T-- != 0; ++c) {
            double d = cin.nextDouble();
            double v = cin.nextDouble();
            double u = cin.nextDouble();
            System.out.printf("Case %d: ", c);
            if (v == 0 || u == 0 || v >= u)
                System.out.println("can't determine");
            else {
                double fastest = d / u;
                double shortest = d / Math.sqrt(u * u - v * v);
                System.out.printf("%.3f\n", Math.abs(fastest - shortest));
            }
        }
    }
}