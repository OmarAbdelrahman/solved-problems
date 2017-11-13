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
            int[] heights = new int[n];
            for (int i = 0; i < n; ++i)
                heights[i] = cin.nextInt();
            int queries = cin.nextInt();
            while (queries-- != 0) {
                int maleHeight = cin.nextInt();
                int[] koko = {-1, -1};
                int lower = 0;
                int upper = n - 1;
                while (lower <= upper) {
                    int mid = (lower + upper) / 2;
                    if (maleHeight >= heights[mid])
                        lower = mid + 1;
                    else {
                        upper = mid - 1;
                        koko[1] = heights[mid];
                    }
                }
                lower = 0;
                upper = n - 1;
                while (lower <= upper) {
                    int mid = (lower + upper) / 2;
                    if (maleHeight <= heights[mid])
                        upper = mid - 1;
                    else {
                        lower = mid + 1;
                        koko[0] = heights[mid];
                    }
                }
                System.out.print(koko[0] == -1 ? "X " : koko[0] + " ");
                System.out.println(koko[1] == -1 ? "X" : koko[1]);
            }
        }
    }
}