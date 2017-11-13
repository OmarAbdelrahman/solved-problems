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
        while (cin.hasNext()) {
            int n = cin.nextInt();
            cin.nextLine();
            char[][] board = new char[n][n];
            Queue<Pair<Pair<Integer, Integer>, Integer>> queue = new LinkedList<Pair<Pair<Integer, Integer>, Integer>>();
            int[][] dist = new int[n][n];
            for (int[] a : dist) Arrays.fill(a, -1);
            for (int i = 0; i < n; i++) {
                board[i] = cin.nextLine().toCharArray();
                for (int j = 0; j < n; j++)
                    if (board[i][j] == '3') {
                        queue.add(Pair.makePair(Pair.makePair(i, j), 0));
                        dist[i][j] = 0;
                    }
            }
            int result = 0;
            while (!queue.isEmpty()) {
                int x = queue.peek().first.first;
                int y = queue.peek().first.second;
                int c = queue.poll().second;
                for (int dx = -1; dx <= 1; dx++)
                    for (int dy = -1; dy <= 1; dy++)
                        if ((dx == 0) ^ (dy == 0)) {
                            int nx = dx + x;
                            int ny = dy + y;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                                if (dist[nx][ny] == -1) {
                                    dist[nx][ny] = c + 1;
                                    queue.add(Pair.makePair(Pair.makePair(nx, ny), c + 1));
                                    if (board[nx][ny] == '1')
                                        result = Math.max(result, dist[nx][ny]);
                                }
                        }
            }
            out.println(result);
        }
    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static<U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0)
                return value;
            return ((Comparable<V>) second).compareTo(o.second);
        }
    }
}