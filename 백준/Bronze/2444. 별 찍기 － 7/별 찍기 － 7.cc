#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int a;
	cin >> a;

	for (int i = 0, p = a; i < a * 2 - 1; i++)
	{
		if (i >= a) p--;
		else p = i;
		for (int j = 0; j < a + p; j++)
		{
			if (j < a - i - 1 && i < a)
			{
				cout << " ";
			}
			else if (i >= a && j < a - p -1 )
			{
				cout << " ";
			}
			else
				cout << "*";
		}

		cout << "\n";
	}
}