#include <cstdio>
#include <cmath>
using namespace std;

#define EPSILON 1e-9

double f(double p, double q, double r, double s, double t, double u, double x) {
	return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
}

bool lower(double x, double y) {
	return x - y < -EPSILON;
}

int main() {
	double p, q, r, s, t, u;
	for (int i; scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF;) {
		if (!p && !q && !r && !s && !t && !u) {
			puts("0.0000");
			continue;
		}
		double lo = 0.0;
		double hi = 1.0;
		double mid = lo;
		double res = lo;
		double a = f(p, q, r, s, t, u, lo);
		double b = f(p, q, r, s, t, u, hi);
		if (a * b > 0) {
			puts("No solution");
			continue;
		}
		while (fabs(hi - lo) > EPSILON) {
			mid = (lo + hi) / 2.0;
			double v = f(p, q, r, s, t, u, mid);
			if (lower(v, 0.0000)) {
				hi = mid;
			} else {
				res = lo = mid;
			}
		}
		printf("%.4lf\n", res);
	}
	return 0;
}