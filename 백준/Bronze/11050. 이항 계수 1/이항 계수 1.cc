#include <iostream>
#include <string>
#include <vector>

int Pascal(int n, int r);
int main()
{
	int row, col;
	
	std::cin >> row >> col;


	std::cout << Pascal(row, col);

	return 0;
}



int Pascal(int n, int r)
{
	int answer = 0;

	if (r == 0 || r == n)
		return 1;

	answer = Pascal(n - 1, r - 1) + Pascal(n - 1, r);

	return answer;
}
