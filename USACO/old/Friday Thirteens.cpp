/*
ID: 1010
PROG: friday
LANG: C++
*/

#include <iostream>
using namespace std;

enum YearType {
	NOT_LEAP,
	LEAP
};

enum WeekDays {
	Saturday,
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday
};

int g_week[7] = {0};
WeekDays day = Monday;

YearType Leap(int);
void GetNumberOfDays(int);
void CheckThirteen(int);
void Display();

int main() {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int numberOfYears;
	cin >> numberOfYears;
	for (int year = 1900; year <= 1900 + numberOfYears - 1; ++year)
		if (Leap(year)) {
			GetNumberOfDays(29);
		} else {
			GetNumberOfDays(28);
		}
	Display();
	return 0;
}

YearType Leap(int p_year) {
	if (p_year % 100 == 0) {
		if (p_year % 400 == 0)
			return LEAP;
	} else {
		if (p_year % 4 == 0)
			return LEAP;
	}
	return NOT_LEAP;
}

void GetNumberOfDays(int p_feb) {
	for (int month = 1; month <= 12; month++) {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				CheckThirteen(31);
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				CheckThirteen(30);
				break;
			case 2:
				CheckThirteen(p_feb);
				break;
		}
	}
}

void CheckThirteen(int p_monthLimit) {
	for (int i = 1; i <= p_monthLimit; i++) {
		switch (day) {
			case Monday:
				if (i == 13)
					g_week[Monday]++;
				day = Tuesday;
				break;
			case Tuesday:
				if (i == 13)
					g_week[Tuesday]++;
				day = Wednesday;
				break;
			case Wednesday:
				if (i == 13)
					g_week[Wednesday]++;
				day = Thursday;
				break;
			case Thursday:
				if (i == 13)
					g_week[Thursday]++;
				day = Friday;
				break;
			case Friday:
				if (i == 13)
					g_week[Friday]++;
				day = Saturday;
				break;
			case Saturday:
				if (i == 13)
					g_week[Saturday]++;
				day = Sunday;
				break;
			case Sunday:
				if (i == 13)
					g_week[Sunday]++;
				day = Monday;
				break;
		}
	}
}

void Display() {
	cout << g_week[0];
	for (int i = 1; i < 7; i++)
		cout << ' ' << g_week[i];
	cout << endl;
}