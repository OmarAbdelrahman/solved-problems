import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            int n = cin.nextInt();
            int max = cin.nextInt();
            int min = max;
            int[] data = new int[n - 1];
            for (int i = 0; i < data.length; ++i)
                data[i] = cin.nextInt();
            int res = Integer.MIN_VALUE;
            for (int num : data) {
                res = Math.max(res, Math.max(max - num, min - num));
                max = Math.max(max, num);
                min = Math.min(min, num);
            }
            System.out.println(res);
        }
    }
}