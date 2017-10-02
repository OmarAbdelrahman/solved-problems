package codeforces;

import fast.io.InputReader;
import fast.io.OutputWriter;

public class ConvexShape {
    public void solve(int testNumber, InputReader cin, OutputWriter out) {
        int n = cin.readInt();
        int m = cin.readInt();
        boolean[][] black = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                black[i][j] = cin.readCharacter() == 'B';
            }
        }
        boolean convex = true;
        for (int sx = 0; sx < n && convex; sx++) {
            for (int sy = 0; sy < m && convex; sy++) {
                for (int tx = 0; tx < n && convex; tx++) {
                    for (int ty = 0; ty < m && convex; ty++) {
                        if (!black[sx][sy] || !black[tx][ty]) continue;
                        convex &= reachable(sx, sy, tx, ty, black);
                    }
                }
            }
        }
        out.printLine(convex ? "YES" : "NO");
    }

    boolean reachable(int sx, int sy, int tx, int ty, boolean[][] black) {
        if (sx == tx) {
            if (sy > ty) {
                int t = sy;
                sy = ty;
                ty = t;
            }
            for (int i = sy; i <= ty; i++) {
                if (!black[sx][i]) {
                    return false;
                }
            }
        } else if (sy == ty) {
            if (sx > tx) {
                int t = sx;
                sx = tx;
                tx = t;
            }
            for (int i = sx; i <= tx; i++) {
                if (!black[i][sy]) {
                    return false;
                }
            }
        } else {
            boolean firstWay = reachable(sx, sy, tx, sy, black) && reachable(tx, sy, tx, ty, black);
            boolean secondWay = reachable(sx, sy, sx, ty, black) && reachable(sx, ty, tx, ty, black);
            if (firstWay || secondWay) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
}
