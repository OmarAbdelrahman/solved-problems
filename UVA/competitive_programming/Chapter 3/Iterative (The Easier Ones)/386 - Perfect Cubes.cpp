#include <cstdio>
using namespace std;

template<class T> inline T cube(T x) {
	return x * x * x;
}

int main() {
	int cb[201], i, x, y, z;
	for (i = 1; i < 201; i++) cb[i] = cube(i);
	for (i = 6; i < 201; i++)
		for (x = 2; x < i; x++)
			for (y = x + 1; y < i; y++)
				for (z = y + 1; z < i; z++)
					if (cb[i] == cube(x) + cube(y) + cube(z))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, x, y, z);
	return 0;
}