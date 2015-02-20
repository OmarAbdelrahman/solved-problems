import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static int[] cache = new int[1 << 12];

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            String str = cin.next();
            int mask = 0;
            for (int i = 0; i < str.length(); ++i)
                if (str.charAt(i) == 'o')
                    mask ^= (1 << i);
            Arrays.fill(cache, -1);
            System.out.println(solve(mask));
        }
    }

    private static int solve(int mask) {
        if (mask <= 0) return 0;
        if (cache[mask] != -1)
            return cache[mask];
        cache[mask] = Integer.MAX_VALUE;
        boolean cant = true;
        for (int i = 0; i < 12; ++i) {
            if (i + 2 < 12 && ok(i, i + 1, i + 2, mask)) {
                cache[mask] = Math.min(cache[mask], solve(mask ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i + 2))));
                cant = false;
            }
            if (i - 1 >= 0 && ok(i, i + 1, i - 1, mask)) {
                cache[mask] = Math.min(cache[mask], solve(mask ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i - 1))));
                cant = false;
            }
        }
        if (cant) {
            int cnt = 0;
            for (int i = 0; i < 12; ++i)
                if ((mask & (1 << i)) != 0)
                    ++cnt;
            cache[mask] = Math.min(cache[mask], cnt);
        }
        return cache[mask];
    }

    private static boolean ok(int a, int b, int c, int mask) {
        return (mask & (1 << a)) != 0 && (mask & (1 << b)) != 0 && (mask & (1 << c)) == 0;
    }
}