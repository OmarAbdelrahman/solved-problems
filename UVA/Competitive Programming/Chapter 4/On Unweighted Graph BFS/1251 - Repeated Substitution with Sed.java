import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (true) {
            int n = Integer.parseInt(cin.nextLine().trim());
            if (n == 0) break;
            String[] a = new String[n];
            String[] b = new String[n];
            for (int i = 0; i < n; ++i) {
                String[] parts = cin.nextLine().split(" ", -1);
                a[i] = parts[0];
                b[i] = parts[1];
            }
            out.println(solve(cin.nextLine().trim(), cin.nextLine().trim(), a, b));
        }
    }

    private static int solve(String src, String trg, String[] a, String[] b) {
        Set<String> set = new HashSet<String>();
        Queue<State> queue = new LinkedList<State>();
        set.add(src);
        for (queue.add(new State(src, 0)); !queue.isEmpty();) {
            String current = queue.peek().current;
            int cost = queue.poll().cost;
            if (current.equals(trg))
                return cost;
            for (int i = 0; i < a.length; ++i) {
                String next = current.replaceAll(a[i], b[i]);
                if (next.equals(current) || next.length() > trg.length())
                    continue;
                if (!set.contains(next)) {
                    queue.add(new State(next, cost + 1));
                    set.add(next);
                }
            }
        }
        return -1;
    }

    static class State {
        int cost;
        String current;

        public State(String current, int cost) {
            this.current = current;
            this.cost = cost;
        }
    }
}