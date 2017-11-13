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
        for (int turn = 1; cin.hasNext(); turn++) {
            int n = cin.nextInt();
            int m = cin.nextInt();
            if (n == 0 && m == 0)
                break;
            cin.nextLine();
            if (turn > 1)
                out.println();
            char[][] board = new char[n][m];
            int x1 = -1;
            int y1 = -1;
            int x2 = -1;
            int y2 = -1;
            for (int i = 0; i < n; i++) {
                board[i] = cin.nextLine().toCharArray();
                for (int j = 0; j < m; j++)
                    if (board[i][j] == 'S') {
                        x1 = i;
                        y1 = j;
                    } else if (board[i][j] == 'T') {
                        x2 = i;
                        y2 = j;
                    }
            }
            int result = getCost(x1, y1, x2, y2, board);
            out.printf("Case #%d\n", turn);
            if (result == -1)
                out.println("destination not reachable");
            else
                out.printf("minimum time = %d sec\n", result);
        }
    }

    private static int getCost(int x1, int y1, int x2, int y2, char[][] board) {
        Queue<State> queue = new LinkedList<State>();
        boolean[][][][] visited = new boolean[board.length][board[0].length][4][5];
        for (boolean[][][] a : visited) for (boolean[][] b : a) for (boolean[] c : b) Arrays.fill(c, false);
        queue.add(new State(x1, y1, 0, 0, 0));
        visited[x1][y1][0][0] = true;
        while (!queue.isEmpty()) {
            int x = queue.peek().x;
            int y = queue.peek().y;
            int d = queue.peek().d;
            int c = queue.peek().c;
            int t = queue.poll().t;
            if (x == x2 && y == y2 && c == 0)
                return t;
            int left = (d + 1) % 4;
            int right = (d - 1 + 4) % 4;
            if (!visited[x][y][left][c]) {
                queue.add(new State(x, y, left, c, t + 1));
                visited[x][y][left][c] = true;
            }
            if (!visited[x][y][right][c]) {
                queue.add(new State(x, y, right, c, t + 1));
                visited[x][y][right][c] = true;
            }
            int forward = (c + 1) % 5;
            switch (d) {
                case 0:
                    if (ok(x - 1, y, board) && !visited[x - 1][y][d][forward]) {
                        queue.add(new State(x - 1, y, d, forward, t + 1));
                        visited[x - 1][y][d][forward] = true;
                    }
                    break;
                case 1:
                    if (ok(x, y + 1, board) && !visited[x][y + 1][d][forward]) {
                        queue.add(new State(x, y + 1, d, forward, t + 1));
                        visited[x][y + 1][d][forward] = true;
                    }
                    break;
                case 2:
                    if (ok(x + 1, y, board) && !visited[x + 1][y][d][forward]) {
                        queue.add(new State(x + 1, y, d, forward, t + 1));
                        visited[x + 1][y][d][forward] = true;
                    }
                    break;
                case 3:
                    if (ok(x, y - 1, board) && !visited[x][y - 1][d][forward]) {
                        queue.add(new State(x, y - 1, d, forward, t + 1));
                        visited[x][y - 1][d][forward] = true;
                    }
                    break;
            }
        }
        return -1;
    }

    private static boolean ok(int x, int y, char[][] board) {
        return x >= 0 && y >= 0 && x < board.length && y < board[0].length && board[x][y] != '#';
    }

    private static class State {
        int x, y, d, c, t;

        State(int x, int y, int d, int c, int t) {
            this.y = y;
            this.d = d;
            this.x = x;
            this.c = c;
            this.t = t;
        }
    }
}