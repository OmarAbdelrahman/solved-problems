#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define FOREACH(i, c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

struct Employee {
	string street_address, home_phone, work_phone;
	string title, first_name, last_name, campus_mailbox;
	string department_title;
	Employee() {}
	Employee(string title, string first, string last, string street, string home, string work, string campus, string department) {
		this->title = title;
		this->first_name = first;
		this->last_name = last;
		this->street_address = street;
		this->home_phone = home;
		this->work_phone = work;
		this->campus_mailbox = campus;
		this->department_title = department;
	}
	bool operator < (const Employee& e) const {
		return this->last_name < e.last_name;
	}
};

void parse(vector<Employee>& data_base, string information, string& department_name) {
	for (int i = 0; i < LENGTH(information); ++i) {
		if (information[i] == ' ') information[i] = '_';
		if (information[i] == ',') information[i] = ' ';
	}
	Employee employee;
	stringstream sin(information);
	sin >> employee.title >> employee.first_name >> employee.last_name
		>> employee.street_address >> employee.home_phone >> employee.work_phone
		>> employee.campus_mailbox;
	employee.department_title = department_name;
	data_base.push_back(employee);
}

void print(string& str) {
	for (int i = 0; i < LENGTH(str); ++i)
		if (str[i] == '_')
			cout << ' ';
		else
			cout << str[i];
}

int main() {
	int kases; cin >> kases;
	cin.ignore();
	vector<Employee> data_base;
	while (kases--) {
		string department_name; getline(cin, department_name);
		for (string information; getline(cin, information) && !information.empty();) {
			parse(data_base, information, department_name);
		}
	}
	sort(data_base.begin(), data_base.end());
	FOREACH(employee, data_base) {
		puts("----------------------------------------");
		print(employee->title); cout << " ";
		print(employee->first_name); cout << " ";
		print(employee->last_name); cout << endl;
		print(employee->street_address); cout << endl;
		cout << "Department: "; print(employee->department_title); cout << endl;
		cout << "Home Phone: "; print(employee->home_phone); cout << endl;
		cout << "Work Phone: "; print(employee->work_phone); cout << endl;
		cout << "Campus Box: "; print(employee->campus_mailbox); cout << endl;
	}
	return 0;
}
