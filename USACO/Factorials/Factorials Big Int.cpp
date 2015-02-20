/*
ID: 1010
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <assert.h>
using namespace std;

#define MAX 4220 + 5

struct BigInteger {
	vector<int> digits;
	static const int BASE, DIGITS;
	BigInteger(int value = 0);
	BigInteger(const char* str);
	int get(int k) const;
	void set(int k, int value);
	void normalize();
	string toString() const;
};

const int BigInteger::BASE = 10000;
const int BigInteger::DIGITS = 4;

BigInteger::BigInteger(int value) {
	for (; value > 0; value /= BASE)
		digits.push_back(value % BASE);
}

BigInteger::BigInteger(const char* str) {
	char buffer[DIGITS + 1]; memset(buffer, '\0', sizeof(buffer));
	for (int length = (int)strlen(str); length > 0; length -= DIGITS) {
		const int digitSize = min(DIGITS, length);
		memcpy(buffer, &str[length - digitSize], digitSize * sizeof(char));
		buffer[digitSize] = '\0';
		digits.push_back(atoi(buffer));
	}
	normalize();
}

int BigInteger::get(int k) const {
	if (k >= (int)digits.size()) return 0;
	else return digits[k];
}

void BigInteger::set(int k, int value) {
	if (k >= (int)digits.size()) digits.resize(k + 1, 0);
	digits[k] = value;
}

void BigInteger::normalize() {
	while (!digits.empty() && digits.back() == 0)
		digits.pop_back();
}

string BigInteger::toString() const {
	if (digits.empty()) return string("0", 1);
	char buffer[DIGITS + 1];
	const int length = sprintf(buffer, "%d", digits.back());
	string str(buffer, length);
	for (int k = (int)digits.size() - 2; k >= 0; --k) {
		sprintf(buffer, "%0*d", DIGITS, digits[k]);
		str.append(buffer, DIGITS);
	}
	return str;
}

BigInteger operator *(const BigInteger& b1, int X) {
	BigInteger b2; int carry = 0;
	for (int k = 0; k < (int)b1.digits.size(); ++k) {
		const int value = b1.digits[k] * X + carry;
		b2.digits.push_back(value % BigInteger::BASE);
		carry = value / BigInteger::BASE;
	}
	if (carry > 0) b2.digits.push_back(carry);
	b2.normalize();
	return b2;
}

BigInteger numbers[MAX];

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	numbers[1] = BigInteger("1");
	for (int i = 2; i <= n; ++i)
		numbers[i] = numbers[i - 1] * i;
	string str = numbers[n].toString();
	for (int i = str.size() - 1; i >= 0; --i)
		if (str[i] != '0') {
			cout << str[i] << endl;
			break;
		}
	return 0;
}