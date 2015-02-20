import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    static private boolean ok(int x, int y, int n, int m, char[][] board) {
        return x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#';
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (true) {
            int n = cin.nextInt();
            int m = cin.nextInt();
            int s = cin.nextInt();
            if (n == 0 && m == 0 && s == 0)
                break;
            char[][] board = new char[n][m];
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            int nowDir = -1;
            Pair<Integer, Integer> position = new Pair<Integer, Integer>();
            cin.nextLine();
            for (int i = 0; i < n; ++i) {
                board[i] = cin.nextLine().toCharArray();
                for (int j = 0; j < board[i].length; ++j) {
                    char ch = board[i][j];
                    switch (ch) {
                        case 'N': nowDir = 0; position = Pair.makePair(i, j); break;
                        case 'S': nowDir = 2; position = Pair.makePair(i, j); break;
                        case 'L': nowDir = 1; position = Pair.makePair(i, j); break;
                        case 'O': nowDir = 3; position = Pair.makePair(i, j); break;
                    }
                }
            }
            String instructions = cin.nextLine();
            int res = 0;
            for (char ch : instructions.toCharArray()) {
                switch (ch) {
                    case 'D':
                        nowDir = (nowDir + 1) % 4;
                        break;
                    case 'E':
                        nowDir = (nowDir + 4 - 1) % 4;
                        break;
                    case 'F':
                        int nx = position.first + dx[nowDir];
                        int ny = position.second + dy[nowDir];
                        if (ok(nx, ny, n, m, board)) {
                            if (board[nx][ny] == '*') {
                                ++res;
                                board[nx][ny] = '.';
                            }
                            position.first = nx;
                            position.second = ny;
                        }
                        break;
                }
            }
            System.out.println(res);
        }
    }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public U first;
    public V second;

    public Pair() {
        this.first = null;
        this.second = null;
    }

    Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
    }

    public String toString() {
        return "(" + this.first + ", " + this.second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0) return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}