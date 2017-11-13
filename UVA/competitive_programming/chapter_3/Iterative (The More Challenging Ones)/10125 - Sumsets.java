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
            if (n == 0) break;
            int[] data = new int[n];
            for (int i = 0; i < n; ++i)
                data[i] = cin.nextInt();
            Arrays.sort(data);
            int koko = get(data);
            System.out.println(koko >= Integer.MAX_VALUE ? "no solution" : koko);
        }
    }

    private static int get(int[] data) {
        int n = data.length;
        for (int d = n - 1; d >= 0; --d)
            for (int a = 0; a < n; ++a) if (a != d)
                for (int b = a + 1; b < n; ++b) if (b != d)
                    for (int c = b + 1; c < n; ++c) if (c != d)
                        if (data[d] == data[a] + data[b] + data[c])
                            return data[d];
        return Integer.MAX_VALUE;
    }
}