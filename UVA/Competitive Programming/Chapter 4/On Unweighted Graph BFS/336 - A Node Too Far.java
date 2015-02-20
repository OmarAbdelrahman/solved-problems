import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int query = 1;
        List<Integer>[] list = new List[33];
        while (cin.hasNext()) {
            int nodes = cin.nextInt();
            if (nodes == 0)
                break;
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int i = 0; i < list.length; i++)
                list[i] = new ArrayList<Integer>();
            int index = 0;
            for (int i = 0; i < nodes; i++) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                Integer val = map.get(x);
                if (val == null)
                    map.put(x, index++);
                val = map.get(y);
                if (val == null)
                    map.put(y, index++);
                list[map.get(x)].add(map.get(y));
                list[map.get(y)].add(map.get(x));
            }
            int[] distance = new int[map.size()];
            while (true) {
                int start = cin.nextInt();
                int steps = cin.nextInt();
                if (start == 0 && steps == 0)
                    break;
                Arrays.fill(distance, -1);
                Queue<Integer> queue = new LinkedList<Integer>();
                queue.add(map.get(start));
                distance[map.get(start).intValue()] = 0;
                while (!queue.isEmpty()) {
                    int now = queue.poll();
                    for (int i = 0; i < list[now].size(); i++) {
                        int next = list[now].get(i);
                        if (distance[next] == -1) {
                            distance[next] = distance[now] + 1;
                            queue.add(next);
                        }
                    }
                }
                int count = 0;
                for (int value : distance)
                    if (value == -1 || value > steps)
                        ++count;
                out.printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", query++, count, start, steps);
            }
        }
    }
}