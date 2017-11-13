import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int TC = cin.nextInt();
        for (int K = 1; TC-- > 0; ++K) {
            int lamps = cin.nextInt();
            int switches = cin.nextInt();
            int[] connected = new int[switches];
            for (int i = 0; i < connected.length; ++i)
                for (int j = 0; j < lamps; ++j)
                    if (cin.nextInt() == 1)
                        connected[i] |= 1 << j;
            int result = solve((1 << lamps) - 1, connected);
            out.printf("Case %d: ", K);
            if (result == -1)
                out.println("IMPOSSIBLE");
            else
                out.println(result);
        }
    }

    private static int solve(int src, int[] connected) {
        Queue<State> queue = new LinkedList<State>();
        boolean[] visited = new boolean[src + 1];
        for (queue.add(new State(src, 0)); !queue.isEmpty();) {
            int mask = queue.peek().mask;
            int cost = queue.poll().cost;
            if (mask == 0)
                return cost;
            for (int curSwitch : connected)
                if (!visited[mask ^ curSwitch]) {
                    queue.add(new State(mask ^ curSwitch, cost + 1));
                    visited[mask ^ curSwitch] = true;
                }
        }
        return -1;
    }

    static class State {
        int mask, cost;

        public State(int mask, int cost) {
            this.mask = mask;
            this.cost = cost;
        }
    }
}