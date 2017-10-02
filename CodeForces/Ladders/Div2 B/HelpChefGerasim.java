package codeforces;

import fast.io.InputReader;
import fast.io.OutputWriter;
import utils.IOUtils;

import java.util.Arrays;

public class HelpChefGerasim {
    public void solve(int testNumber, InputReader cin, OutputWriter out) {
        int n = cin.readInt();
        int[] vs = IOUtils.readIntArray(cin, n);
        int minIndex = -1;
        int max = -1;
        int maxIndex = -1;
        int min = 12345;
        for (int i = 0; i < n; i++) {
            if (vs[i] > max) {
                max = vs[i];
                maxIndex = i;
            }
            if (vs[i] < min) {
                min = vs[i];
                minIndex = i;
            }
        }
        if (vs[minIndex] == vs[maxIndex]) {
            out.printLine("Exemplary pages.");
        } else {
            int poured = (vs[maxIndex] - vs[minIndex]) / 2;
            vs[minIndex] += poured;
            vs[maxIndex] -= poured;
            if (Arrays.stream(vs).min().getAsInt() == Arrays.stream(vs).max().getAsInt()) {
                out.printFormat("%d ml. from cup #%d to cup #%d.", poured, minIndex + 1, maxIndex + 1);
            } else {
                out.printLine("Unrecoverable configuration.");
            }
        }
    }
}
