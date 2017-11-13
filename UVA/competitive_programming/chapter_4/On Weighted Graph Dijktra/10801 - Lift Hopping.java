import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

import static java.lang.System.out;

public class Main {
    final static int MAXF = 101;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int elevators = cin.nextInt();
            int target = cin.nextInt();
            ArrayList<Integer>[] list = new ArrayList[elevators];
            for (int i = 0; i < list.length; ++i)
                list[i] = new ArrayList<Integer>();
            int[] time = new int[elevators];
            for (int i = 0; i < time.length; ++i)
                time[i] = cin.nextInt();
            cin.nextLine();
            for (int i = 0; i < elevators; ++i) {
                String[] parts = cin.nextLine().split(" ", -1);
                for (String part : parts)
                    list[i].add(Integer.parseInt(part));
            }
            int result = solve(target, time, list);
            if (result == -1)
                out.println("IMPOSSIBLE");
            else
                out.println(result);
        }
    }

    private static int solve(int target, int[] time, ArrayList<Integer>[] list) {
        boolean[][] visited = new boolean[MAXF][time.length];
        int[] distance = new int[MAXF];
        Arrays.fill(distance, Integer.MAX_VALUE / 2);
        distance[0] = 0;
        PriorityQueue<State> queue = new PriorityQueue<State>();
        for (int i = 0; i < list.length; ++i)
            if (list[i].contains(0))
                queue.add(new State(0, i, 0));
        while (!queue.isEmpty()) {
            int index = queue.peek().index;
            int elevator = queue.peek().elevator;
            int cost = queue.poll().cost;
            if (visited[index][elevator])
                continue;
            visited[index][elevator] = true;
            if (index == target)
                return distance[target];
            for (int i = 0; i < time.length; ++i)
                if (list[i].contains(index)) {
                    for (int floor : list[i])
                        if (floor != index) {
                            int newCost = (Math.abs(floor - index) * time[i]) + cost + (i != elevator ? 60 : 0);
                            if (newCost < distance[floor]) {
                                distance[floor] = newCost;
                                queue.add(new State(floor, i, newCost));
                            }
                        }
                }
        }
        return -1;
    }

    static class State implements Comparable<State> {
        int index;
        int cost;
        int elevator;

        State(int index, int elevator, int cost) {
            this.index = index;
            this.cost = cost;
            this.elevator = elevator;
        }

        public int compareTo(State state) {
            return cost - state.cost;
        }
    }
}