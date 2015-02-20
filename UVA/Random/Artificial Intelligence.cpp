#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

bool FindVolt(const string &p_problem, int &p_position)
{
	p_position = p_problem.find("U=");

	if (p_position == string::npos)
		return false;
	else return true;
}

bool FindCurrent(const string &p_problem, int &p_position)
{
	p_position = p_problem.find("I=");

	if (p_position == string::npos)
		return false;
	else return true;
}

bool FindPower(const string &p_problem, int &p_position)
{
	p_position = p_problem.find("P=");

	if (p_position == string::npos)
		return false;
	else return true;
}

double StringToDouble(string p_number)
{
	char character;
	double number;

	bool negative = false;
	if (p_number[0] == '-')
	{
		p_number.erase(0, 1);
		negative = true;
	}

	istringstream stream(p_number);
	stream >> number >> character;

	if (character == 'M')
		number *= 1000000;
	else if (character == 'k')
		number *= 1000;
	else if (character == 'm')
		number /= 1000;

	if (number != 0.00 && negative)
		number *= -1;

	return number;
}

int main()
{
	int N;

	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		string problem;
		getline(cin, problem);
	
		int u_position;
		int p_position, c_position;

		bool P = FindPower(problem, p_position);
		bool U = FindVolt(problem, u_position);
		bool I = FindCurrent(problem, c_position);

		cout << "Problem #" << i << endl;

		if (P && U)
		{
			string power = "";
			string volt = "";

			for (int i = p_position + 2; problem[i] != 'W'; i++)
				power += problem[i];

			for (int i = u_position + 2; problem[i] != 'V'; i++)
				volt += problem[i];

			double v_value = StringToDouble(volt);
			double p_value = StringToDouble(power);

			if (p_value == 0.00)
			{
				puts("I=0.00A\n");
				continue;
			}

			cout << "I=" << setiosflags(ios::fixed) << setprecision(2) << p_value / v_value << "A" << endl << endl;
		}
		else if (P && I)
		{
			string power = "";
			string current = "";

			for (int i = p_position + 2; problem[i] != 'W'; i++)
				power += problem[i];
			
			for (int i = c_position + 2; problem[i] != 'A'; i++)
				current += problem[i];

			double c_value = StringToDouble(current);
			double p_value = StringToDouble(power);

			if (p_value == 0.00)
			{
				puts("U=0.00V\n");
				continue;
			}

			cout << "U=" << setiosflags(ios::fixed) << setprecision(2) << p_value / c_value << "V" << endl << endl;
		}
		else if (I && U)
		{
			string volt = "";
			string current = "";

			for (int i = u_position + 2; problem[i] != 'V'; i++)
				volt += problem[i];

			for (int i = c_position + 2; problem[i] != 'A'; i++)
				current += problem[i];

			double c_value = StringToDouble(current);
			double v_value = StringToDouble(volt);

			if (c_value == 0.00 || v_value == 0.00)
			{
				puts("P=0.00W\n");
				continue;
			}

			cout << "P=" << setiosflags(ios::fixed) << setprecision(2) << v_value * c_value  << "W" << endl << endl;
		}
	}

	return 0;
}