import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int surplus = cin.nextInt();
            int deficit = cin.nextInt();
            int koko = -1;
            for (int mask = 0; mask < (1 << 12); ++mask) {
                int totalSurplus = 0;
                boolean ok = true;
                for (int i = 0; i < 12; ++i) {
                    if ((mask & (1 << i)) != 0)
                        totalSurplus += surplus;
                    else
                        totalSurplus -= deficit;
                    if (i + 5 <= 12) {
                        int eachGroup = 0;
                        for (int j = i; j < i + 5; ++j) {
                            if ((mask & (1 << j)) != 0)
                                eachGroup += surplus;
                            else
                                eachGroup -= deficit;
                        }
                        if (eachGroup >= 0)
                            ok = false;
                    }
                }
                if (ok)
                    koko = Math.max(koko, totalSurplus);
            }
            System.out.println(koko == -1 ? "Deficit" : koko);
        }
    }
}