#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
//짝수는 숫자 홀수는 연산자 
//묶을때는 숫자 연산자 숫자로 묶어야됨

char input[19];
int n;
int ret = -2147483648;

int calculate(int a, int b, char oper)
{
	switch (oper)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

void dfs(int numIdx, int value)
{
	char operIdx = numIdx + 1;
	
	if (numIdx >= n) return;
	if (numIdx == n - 1)
	{
		ret = std::max(ret, value);
		return;
	}

	if (numIdx + 4 < n)
	{
	    int case1 = calculate(input[numIdx + 2] - '0', input[numIdx + 4] - '0', input[numIdx + 3]);
		dfs(numIdx + 4, calculate(value, case1, input[numIdx + 1]));
	}

	if (numIdx + 2 < n)
	{
		dfs(numIdx + 2, calculate(value, input[numIdx + 2] - '0', input[numIdx + 1]));
	}


}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> input[i];

	dfs(0, input[0] - '0');
	std::cout << ret;
}