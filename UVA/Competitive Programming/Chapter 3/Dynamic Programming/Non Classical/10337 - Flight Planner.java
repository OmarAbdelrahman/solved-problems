import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    static int INFINITY = Integer.MAX_VALUE / 2;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            int distance = cin.nextInt();
            int[][] cost = new int[10][distance / 100];
            for (int i = cost.length - 1; i >= 0; --i)
                for (int j = 0; j < cost[i].length; ++j)
                    cost[i][j] = cin.nextInt();
            int[][] cache = new int[cost.length][cost[0].length];
            for (int[] a : cache) Arrays.fill(a, -1);
            out.println(solve(0, 0, cache, cost));
            out.println();
        }
    }

    private static int solve(int altitude, int distance, int[][] cache, int[][] cost) {
        if (distance == cost[0].length && altitude == 0)
            return 0;
        if (altitude < 0 || altitude > 9 || distance == cost[0].length)
            return INFINITY;
        if (cache[altitude][distance] != -1)
            return cache[altitude][distance];
        if (altitude == 0) {
            if (distance == cost[0].length - 1)
                return cache[altitude][distance] = 30 - cost[altitude][distance] + solve(altitude, distance + 1, cache, cost);
            else {
                int climb = 60 - cost[altitude][distance] + solve(altitude + 1, distance + 1, cache, cost);
                int stay = 30 - cost[altitude][distance] + solve(altitude, distance + 1, cache, cost);
                return cache[altitude][distance] = Math.min(climb, stay);
            }
        } else {
            int climb = 60 - cost[altitude][distance] + solve(altitude + 1, distance + 1, cache, cost);
            int stay = 30 - cost[altitude][distance] + solve(altitude, distance + 1, cache, cost);
            int sink = 20 - cost[altitude][distance] + solve(altitude - 1, distance + 1, cache, cost);
            return cache[altitude][distance] = Math.min(Math.min(climb, stay), sink);
        }
    }
}