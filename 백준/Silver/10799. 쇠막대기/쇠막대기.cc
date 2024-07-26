#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int overLap = 0;

	string input;
	int sum = 0;
	char remember = NULL;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case '(':
			++overLap;
			remember = '(';
			break;
		case ')':
			if (remember == ')')	sum++;
			else					sum += (overLap - 1);
			remember = ')';
			--overLap;
			break;
		default:
			break;
		}
	}

	cout << sum;

		
	return 0;
}