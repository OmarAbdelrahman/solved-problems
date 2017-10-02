package codeforces;

import fast.io.InputReader;
import fast.io.OutputWriter;

public class Surrounded {
    public void solve(int testNumber, InputReader cin, OutputWriter out) {
        double x1 = cin.readDouble();
        double y1 = cin.readDouble();
        double r1 = cin.readDouble();
        double x2 = cin.readDouble();
        double y2 = cin.readDouble();
        double r2 = cin.readDouble();
        double d = Math.hypot(x1 - x2, y1 - y2);
        if (d >= r1 + r2) {
            out.printLine((d - r1 - r2) / 2);
        } else if (d <= Math.abs(r1 - r2)) {
            out.printLine((Math.max(r1, r2) - d - Math.min(r1, r2)) / 2);
        } else {
            out.printLine(0.0);
        }
    }
}
