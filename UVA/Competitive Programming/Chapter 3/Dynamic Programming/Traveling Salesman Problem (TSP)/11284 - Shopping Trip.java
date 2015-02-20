import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.*;

public class Main {
    final static double INFINITY = 1e9;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            int stores = cin.nextInt() + 1;
            int roads = cin.nextInt();
            double[][] dist = new double[stores][stores];
            for (double[] row : dist) Arrays.fill(row, INFINITY);
            for (int i = 0; i < dist.length; ++i)
                dist[i][i] = 0.0;
            for (int i = 0; i < roads; ++i) {
                int a = cin.nextInt();
                int b = cin.nextInt();
                dist[a][b] = dist[b][a] = Math.min(dist[a][b], cin.nextDouble());
            }
            for (int k = 0; k < dist.length; ++k)
                for (int i = 0; i < dist.length; ++i)
                    for (int j = 0; j < dist.length; ++j)
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
            int opera = cin.nextInt();
            int[] store = new int[opera];
            double[] price = new double[opera];
            double[][] cost = new double[opera + 1][opera + 1];
            for (int i = 0; i < opera; ++i) {
                store[i] = cin.nextInt();
                price[i] = cin.nextDouble();
                cost[0][i + 1] = cost[i + 1][0] = dist[0][store[i]];
            }
            for (int i = 1; i < cost.length; ++i)
                for (int j = 1; j < cost.length; ++j)
                    cost[i][j] = dist[store[i - 1]][store[j - 1]];
            double[][] dp = new double[cost.length][1 << cost.length];
            for (int i = 0; i < cost.length; ++i)
                dp[i][(1 << cost.length) - 1] = -cost[i][0];
            for (int mask = (1 << cost.length) - 2; mask >= 0; --mask)
                for (int index = 0; index < cost.length; ++index)
                    if ((mask & (1 << index)) != 0) {
                        dp[index][mask] = -INFINITY;
                        for (int nxt = 1; nxt < cost.length; ++nxt)
                            if ((mask & (1 << nxt)) == 0) {
                                double take = dp[nxt][mask | (1 << nxt)] - cost[index][nxt] + price[nxt - 1];
                                double dont = dp[index][mask | (1 << nxt)];
                                dp[index][mask] = Math.max(dp[index][mask], Math.max(take, dont));
                            }
                    }
            if (dp[0][1] <= 0 || dp[0][1] < 1e-9)
                out.println("Don't leave the house");
            else
                out.printf("Daniel can save $%.2f\n", dp[0][1]);
        }
    }
}