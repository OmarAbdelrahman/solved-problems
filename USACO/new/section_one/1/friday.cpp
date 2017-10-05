/*
ID: omar.se1
LANG: C++11
TASK: friday
 */

#include <bits/stdc++.h>
using namespace std;

const int BASE_YEAR = 1900;
const int DAYS_IN_WEEK = 7;

struct day {
  static const int MONDAY = 0;
  static const int TUESDAY = 1;
  static const int WEDNESDAY = 2;
  static const int THURSDAY = 3;
  static const int FRIDAY = 4;
  static const int SATURDAY = 5;
  static const int SUNDAY = 6;
};

struct month {
  static const int JANUARY = 0;
  static const int FEBRUARY = 1;
  static const int MARCH = 2;
  static const int APRIL = 3;
  static const int MAY = 4;
  static const int JUNE = 5;
  static const int JULY = 6;
  static const int AUGUST = 7;
  static const int SEPTEMBER = 8;
  static const int OCTOBER = 9;
  static const int NOVEMBER = 10;
  static const int DECEMBER = 11;

  static const int days_in_month[12];

  static int get_days(const int year, const int given_month) {
    if (given_month == FEBRUARY) {
      bool is_leap = (year % 100 == 0 ? year % 400 == 0 : year % 4 == 0);
      return days_in_month[given_month] + (int) is_leap;
    }
    return days_in_month[given_month];
  }
};

const int month::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  int n;
  scanf("%d", &n);
  int cur_day = day::MONDAY;
  vector<int> day_freq(DAYS_IN_WEEK, 0);
  for (int count = 0; count < n; count++) {
    const int year = BASE_YEAR + count;
    for (int m = 0; m < 12; m++) {
      const int days_in_month = month::get_days(year, m);
      for (int d = 0; d < days_in_month; d++) {
        if (d == 12) {
          day_freq[cur_day]++;
        }
        (cur_day += 1) %= DAYS_IN_WEEK;
      }
    }
  }
  int day_index = day::SATURDAY;
  for (int i = 0; i < DAYS_IN_WEEK; i++) {
    if (i) printf(" ");
    printf("%d", day_freq[day_index]);
    (day_index += 1) %= DAYS_IN_WEEK;
  }
  printf("\n");
  return 0;
}
