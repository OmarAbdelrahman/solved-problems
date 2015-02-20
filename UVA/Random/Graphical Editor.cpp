#include <iostream>
#include <queue>
#include <string>
using namespace std;

char **image;
char colour = NULL;
short n, m;

bool Available(short row, short coloumn)
{
	if (row < 0 || coloumn < 0 || row >= n ||coloumn >= m)
		return false;
	return true;
}

void Clear();
void Display();
void Draw_V(short&, short&, short&);
void Draw_H(short&, short&, short&);
void ColourRegion(short&, short&);

int main()
{
	char command = NULL;
	string imageName;
	short row_1, coloumn_1;
	short row_2, coloumn_2;
	while (cin >> command)
	{
		switch (command)
		{
		case 'I':
			cin >> m >> n;
			image = new char*[n];
			for (short i = 0; i < n; i++)
				image[i] = new char[m];
			Clear();
			break;

		case 'C':
			Clear();
			break;

		case 'L':
			cin >> row_1 >> coloumn_1 >> colour;
			image[coloumn_1 - 1][row_1 - 1] = colour;
			break;

		case 'V':
			cin >> row_1 >> coloumn_1 >> coloumn_2 >> colour;
			coloumn_1 < coloumn_2 ? Draw_V(coloumn_1, coloumn_2, row_1) : Draw_V(coloumn_2, coloumn_1, row_1);
			break;

		case 'H':
			cin >> row_1 >> row_2 >> coloumn_1 >> colour;
			row_1 < row_2 ? Draw_H(row_1, row_2, coloumn_1) : Draw_H(row_2, row_1, coloumn_1);
			break;

		case 'K':
			cin >> row_1 >> coloumn_1 >> row_2 >> coloumn_2 >> colour;
			for (short i = coloumn_1 - 1; i <= coloumn_2 - 1; i++)
				for (short j = row_1 - 1; j <= row_2 - 1; j++)
					image[i][j] = colour;
			break;

		case 'F':
			cin >> row_1 >> coloumn_1 >> colour;
			if (image[--row_1][--coloumn_1] == colour) break;
			ColourRegion(row_1, coloumn_1);
			break;

		case 'S':
			cin.ignore();
			getline(cin, imageName);
			cout << imageName << endl;
			Display();
			break;

		case 'X':
			for (short i = 0; i < n; i++)
				delete[] image[i];
			delete[] image;
			return 0;
		}
	}
	return 0;
}

void Clear()
{
	for (short i = 0; i < n; i++)
		fill(image[i], image[i] + m, 'O');
}

void Display()
{
	for (short i = 0; i < n; i++)
	{
		for (short j = 0; j < m; j++)
			cout << image[i][j];
		cout << endl;
	}
}

void Draw_V(short& coloumn_1, short& coloumn_2, short& row_1)
{
	for (short i = coloumn_1; i <= coloumn_2; i++)
		image[i - 1][row_1 - 1] = colour;
}

void Draw_H(short& row_1, short& row_2, short& coloumn_1)
{
	for (short i = row_1; i <= row_2; i++)
		image[coloumn_1 - 1][i - 1] = colour;
}

void ColourRegion(short& row, short& coloumn)
{
	char roundColour = image[coloumn][row];
	image[coloumn][row] = colour;
	short r_Row[] = {1, -1, 0, 0};
	short r_Col[] = {0, 0, 1, -1};
	pair<short, short> currentPosition, toPush;
	queue<pair<short, short> > fillRegion;
	currentPosition = make_pair(coloumn, row);
	fillRegion.push(currentPosition);
	while (!fillRegion.empty())
	{
		currentPosition = fillRegion.front();
		for (int i = 0; i < 4; i++)
			if (Available(currentPosition.first + r_Row[i], currentPosition.second + r_Col[i]))
				if (image[currentPosition.first + r_Row[i]][currentPosition.second + r_Col[i]] == roundColour)
				{
					toPush.first = currentPosition.first + r_Row[i];
					toPush.second = currentPosition.second + r_Col[i];
					image[toPush.first][toPush.second] = colour;
					fillRegion.push(toPush);
				}
		fillRegion.pop();
	}
}