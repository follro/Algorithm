#include <iostream>
#include <string>
#include <vector>

int GCD(int a, int b);


int main()
{
	int input1, input2;
	int gcd, lcm;
	std::cin >> input1 >> input2;


	gcd = GCD(input1, input2);
	lcm = input1 * input2 / gcd;

	std::cout << gcd << "\n" << lcm;

	

	return 0;
}

int GCD(int a, int b)
{
	int big, small, remainder;

	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	remainder = big % small;

	if (remainder == 0)
		return small;

	return GCD(small, remainder);
}