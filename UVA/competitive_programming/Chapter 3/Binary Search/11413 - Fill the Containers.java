import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int vessels = cin.nextInt();
            int containers = cin.nextInt();
            int[] capacity = new int[vessels];
            for (int i = 0; i < capacity.length; ++i)
                capacity[i] = cin.nextInt();
            int left = 0;
            int right = (int) 1e9 + 5;
            for (int i = 0; i < 60; ++i) {
                int mid = (left + right) / 2;
                if (can(mid, containers, capacity))
                    right = mid;
                else
                    left = mid;
            }
            out.println(right);
        }
    }

    private static boolean can(int x, int containers, int[] capacity) {
        int max = Integer.MIN_VALUE;
        int used = 1;
        int curCap = 0;
        for (int cap : capacity) {
            max = Math.max(max, cap);
            curCap += cap;
            if (curCap > x) {
                curCap = cap;
                ++used;
            }
        }
        if (max > x)
            return false;
        return used <= containers;
    }
}