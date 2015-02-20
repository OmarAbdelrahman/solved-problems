import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int fcluster = cin.nextInt();
            if (fcluster == 0)
                break;
            int rcluster = cin.nextInt();
            int[] front = new int[fcluster];
            int[] rear = new int[rcluster];
            for (int i = 0; i < fcluster; ++i)
                front[i] = cin.nextInt();
            for (int i = 0; i < rcluster; ++i)
                rear[i] = cin.nextInt();
            double[] ratios = new double[fcluster * rcluster];
            int index = 0;
            for (int i = 0; i < rear.length; ++i)
                for (int j = 0; j < front.length; ++j)
                    ratios[index++] = (double) rear[i] / (double) front[j];
            Arrays.sort(ratios);
            double res = Double.MIN_VALUE;
            for (int i = 0; i < ratios.length - 1; ++i)
                res = Math.max(res, ratios[i + 1] / ratios[i]);
            System.out.printf("%.2f\n", res);
        }
    }
}