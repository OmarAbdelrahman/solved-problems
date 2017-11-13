import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int T = cin.nextInt();
            if (T == -1) break;
            while (T-- != 0) {
                int D = cin.nextInt();
                int I = cin.nextInt();
                int index = 1;
                for (int depth = 0; depth + 1 < D; ++depth) {
                    if (I % 2 != 0)
                        index *= 2;
                    else
                        index = index * 2 + 1;
                    I = (I + 1) / 2;
                }
                out.println(index);
            }
        }
    }
}