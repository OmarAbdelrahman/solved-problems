package codeforces;

import fast.io.InputReader;
import fast.io.OutputWriter;

public class RunningStudent {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int busSpeed = in.readInt();
        int studentSpeed = in.readInt();
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = in.readInt();
        }
        int tx = in.readInt();
        int ty = in.readInt();
        int busIndex = -1;
        double minTime = Double.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            double busToStation = (double) xs[i] / busSpeed;
            double timeToTarget = Math.hypot((double) xs[i] - tx, ty) / studentSpeed;
            if (timeToTarget + busToStation <= minTime) {
                busIndex = i + 1;
                minTime = timeToTarget + busToStation;
            }
        }
        out.printLine(busIndex);
    }
}
