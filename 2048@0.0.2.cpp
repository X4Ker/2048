#include <iostream>

using namespace std;

unsigned short a[4][4];

void printarray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 0) {
				cout << '*'  << ' ';
			}
			else {
				cout << a[i][j] << ' ';
			}
		}
		cout << endl;
	}
}

void seed() {
	bool b = true;
	int x, y;
	while (b) {
		x = rand() % 4;
		y = rand() % 4;
		if (a[y][x] == 0) {
			a[y][x] = ((rand() % 11) > 0 ? 2 : 4);
			b = false;
		}

	}
}

bool move_down() 
{
	bool q = false;
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i - 1][j];
				a[i - 1][j] = 0;
				q = true;
			}
		}
	}
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (a[i][j] != 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (a[i][j] == a[k][j])
					{
						a[i][j] += a[k][j];
						a[k][j] = 0;
						q = true;
					}
				}
			}
		}
	}
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i - 1][j];
				a[i - 1][j] = 0;
				q = true;
			}
		}
	} 
	return q;
}

bool move_up() 
{
	bool q = false;
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i + 1][j];
				a[i + 1][j] = 0;
				q = true;
			}
		}
	}
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 0; i <= 3; i++)
		{
			if (a[i][j] != 0)
			{
				for (int k = i + 1; k <= 3; k++)
				{
					if (a[i][j] == a[k][j])
					{
						a[i][j] += a[k][j];
						a[k][j] = 0;
						q = true;
					}
				}
			}
		}
	}
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i + 1][j];
				a[i + 1][j] = 0;
				q = true;
			}
		}
	}
	return q;
}

bool move_left()
{
	bool q = false;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i][j + 1];
				a[i][j + 1] = 0;
				q = true;
			}
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (a[i][j] != 0)
			{
				for (int k = j + 1; k <= 3; k++)
				{
					if (a[i][j] == a[i][k])
					{
						a[i][j] += a[i][k];
						a[i][k] = 0;
						q = true;
					}
				}
			}
		}
	} 
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i][j + 1];
				a[i][j + 1] = 0;
				q = true;
			}
		}
	}
	return q;
} 

bool move_right()
{
	bool q = false;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j >= 1; j--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i][j - 1];
				a[i][j - 1] = 0;
				q = true;
			}
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (a[i][j] != 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (a[i][j] == a[i][k])
					{
						a[i][j] += a[i][k];
						a[i][k] = 0;
						q = true;
					}
				}
			}
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j >= 1; j--)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = a[i][j - 1];
				a[i][j - 1] = 0;
				q = true;
			}
		}
	}
	return q;
}

int main() {
	bool q = true;
	char ch;
	while (q == true) {
		seed();
		seed();
		printarray();
		cin >> ch;
		switch (ch) {
		case 'j':
			q = move_down();
			break;
		case 'k':
			q = move_up();
			break;
		case 'h':
			q = move_left();
			break;
		case 'l':
			q = move_right();
			break;
		case 'q':
			q = false;
			break;
		}
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	return 0;
}
