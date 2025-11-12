#include<iostream>

long long divide(long long num, long long exponent, long long divideNum);


int main()
{
	long long a, b, c;

	std::cin >> a >> b >> c;
	
	std::cout << divide(a, b, c);

	
	return 0;
}

long long divide(long long num, long long exponent, long long divideNum)
{
	if (exponent == 1)
		return num % divideNum;

	long long half = divide(num, exponent / 2, divideNum) % divideNum;
	long long result = (half * half) % divideNum;
	if (exponent & 1)
		return (result * (num % divideNum)) % divideNum;
	else
		return result;
}
