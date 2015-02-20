#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	string output;

	for ( ; getline(cin, input); ) {
		for ( ; input.size() != 0; ) {
			string temp = input.substr(0, input.find(' '));
			input.erase(0, temp.size() + 1);
			reverse(temp.begin(), temp.end());
			output += (temp += ' ');
		}
		output.erase(output.size() - 1, 1);
		cout << output << endl;
		output.clear();
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////

package learning;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String str = new String();

        while (cin.hasNext()) {
            str = cin.nextLine();
            String[] tokens = str.split(" ");
            StringBuilder temp = new StringBuilder();
            StringBuilder b;

            for (String token : tokens) {
                b = new StringBuilder(token);
                temp.append(b.reverse());
                temp.append(" ");
            }
            temp.deleteCharAt(temp.length() - 1);
            System.out.println(temp.toString());
        }
    }
}