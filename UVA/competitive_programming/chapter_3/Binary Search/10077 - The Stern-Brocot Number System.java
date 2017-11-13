import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    static class Fraction implements Comparable<Fraction> {
        int P;
        int Q;

        Fraction() {
            this.P = 0;
            this.Q = 1;
        }

        Fraction(int P, int Q) {
            int g = gcd(P, Q);
            P /= g;
            Q /= g;
            if (Q < 0) {
                P = -P;
                Q = -Q;
            }
            this.P = P;
            this.Q = Q;
        }

        public Fraction add(Fraction B) {
            return new Fraction(this.P + B.P, this.Q + B.Q);
        }

        private int gcd(int a, int b) {
            while (b > 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        public int compareTo(Fraction B) {
            if (this.P * B.Q == B.P * this.Q)
                return 0;
            if (this.P * B.Q < B.P * this.Q)
                return -1;
            return 1;
        }
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            Fraction target = new Fraction(cin.nextInt(), cin.nextInt());
            if (target.P == target.Q && target.P == 1)
                break;
            Fraction left = new Fraction(0, 1);
            Fraction right = new Fraction(1, 0);
            Fraction root = new Fraction(1, 1);
            String res = "";
            while (root.compareTo(target) != 0) {
                int diff = root.compareTo(target);
                if (diff == -1) {
                    left = new Fraction(root.P, root.Q);
                    root = root.add(right);
                    res += "R";
                } else if (diff == 1) {
                    right = new Fraction(root.P, root.Q);
                    root = root.add(left);
                    res += "L";
                }
            }
            out.println(res);
        }
    }
}