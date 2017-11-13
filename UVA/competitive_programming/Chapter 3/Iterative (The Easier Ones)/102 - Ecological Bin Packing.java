import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static char[][] perm = {
        { 'B', 'C', 'G' },
        { 'B', 'G', 'C' },
        { 'C', 'B', 'G' },
        { 'C', 'G', 'B' },
        { 'G', 'B', 'C' },
        { 'G', 'C', 'B' }
    };

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int[] bin = new int[256];
        while (cin.hasNext()) {
            int[] data = new int[9];
            for (int i = 0; i < data.length; ++i)
                data[i] = cin.nextInt();
            int res = Integer.MAX_VALUE;
            String binType = "";
            for (int i = 0; i < perm.length; ++i) {
                int cost = 0;
                bin[perm[i][0]] = 0;
                bin[perm[i][1]] = 1;
                bin[perm[i][2]] = 2;
                for (int j = 0; j < 3; ++j) {
                    char ch = perm[i][j];
                    int index = bin[ch];
                    if (index == 0) {
                        if (ch == 'B') {
                            cost += data[3];
                            cost += data[6];
                        } else if (ch == 'G') {
                            cost += data[4];
                            cost += data[7];
                        } else if (ch == 'C') {
                            cost += data[5];
                            cost += data[8];
                        }
                    } else if (index == 1) {
                        if (ch == 'B') {
                            cost += data[0];
                            cost += data[6];
                        } else if (ch == 'G') {
                            cost += data[1];
                            cost += data[7];
                        } else if (ch == 'C') {
                            cost += data[2];
                            cost += data[8];
                        }
                    } else if (index == 2) {
                        if (ch == 'B') {
                            cost += data[0];
                            cost += data[3];
                        } else if (ch == 'G') {
                            cost += data[1];
                            cost += data[4];
                        } else if (ch == 'C') {
                            cost += data[2];
                            cost += data[5];
                        }
                    }
                }
                if (cost < res) {
                    res = cost;
                    binType = "";
                    for (int j = 0; j < 3; ++j)
                        binType += perm[i][j];
                }
            }
            System.out.println(binType + " " + res);
        }
    }
}