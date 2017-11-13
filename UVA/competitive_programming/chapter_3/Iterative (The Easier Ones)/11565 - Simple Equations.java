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
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int A = cin.nextInt();
            int B = cin.nextInt();
            int C = cin.nextInt();
            int[] koko = { Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE };
            for (int x = -100; x <= 100; ++x)
                for (int y = -100; y <= 100; ++y) if (y != x)
                    for (int z = -100; z <= 100; ++z) if (z != y && z != x) {
                        if (x + y + z == A && x * y * z == B && (x * x) + (y * y) + (z * z) == C) {
                            if (x < koko[0]) {
                                koko[0] = x;
                                koko[1] = y;
                                koko[2] = z;
                            } else if (x == koko[0]) {
                                if (y < koko[1]) {
                                    koko[0] = x;
                                    koko[1] = y;
                                    koko[2] = z;
                                }
                            }
                        }
                    }
            if (koko[0] == Integer.MAX_VALUE)
                System.out.println("No solution.");
            else
                System.out.printf("%d %d %d\n", koko[0], koko[1], koko[2]);
        }
    }
}