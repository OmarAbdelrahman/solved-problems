import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (true) {
            int n = cin.nextInt();
            int d = cin.nextInt();
            int r = cin.nextInt();
            if (n == 0 && d == 0 && r == 0)
                break;
            int[] morning = new int[n];
            int[] evening = new int[n];
            for (int i = 0; i < n; ++i)
                morning[i] = cin.nextInt();
            for (int i = 0; i < n; ++i)
                evening[i] = cin.nextInt();
            Arrays.sort(morning);
            Arrays.sort(evening);
            int res = 0;
            for (int i = 0; i < n; ++i) {
                int val = morning[i] + evening[n - i - 1];
                if (val > d) res += (val - d) * r;
            }
            System.out.println(res);
        }
    }
}