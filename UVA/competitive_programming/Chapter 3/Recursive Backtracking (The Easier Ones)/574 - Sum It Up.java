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
            int total = cin.nextInt();
            int n = cin.nextInt();
            if (n == 0) break;
            int[] data = new int[n];
            for (int i = 0; i < n; ++i)
                data[i] = cin.nextInt();
            Set<Data> set = new TreeSet<Data>();
            System.out.printf("Sums of %d:\n", total);
            for (int mask = 0; mask < (1 << n); ++mask) {
                int sum = 0;
                int cnt = 0;
                for (int i = 0; i < n; ++i)
                    if ((mask & (1 << i)) != 0) {
                        sum += data[i];
                        ++cnt;
                    }
                if (sum == total) {
                    Data now = new Data();
                    now.list = new int[cnt];
                    for (int i = 0, j = 0; i < n; ++i)
                        if ((mask & (1 << i)) != 0)
                            now.list[j++] = data[i];
                    set.add(now);
                }
            }
            if (set.size() == 0)
                System.out.println("NONE");
            else {
                for (Data nowData : set) {
                    System.out.print(nowData.list[0]);
                    for (int i = 1; i < nowData.list.length; ++i)
                        System.out.print("+" + nowData.list[i]);
                    System.out.println();
                }
            }
        }
    }

    static class Data implements Comparable<Data> {
        int[] list;

        public int compareTo(Data d) {
            if (list.length < d.list.length)
                return 1;
            for (int i = 0; i < list.length; ++i)
                if (list[i] > d.list[i])
                    return -1;
                else if (list[i] < d.list[i])
                    return 1;
            return 0;
        }
    }
}