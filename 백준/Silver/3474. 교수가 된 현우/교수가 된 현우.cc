#include<iostream>
#include<algorithm>

int n;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;

	int input;
	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		int r5 = 0;
		
		for (int j = 5; j <= input; j *= 5)
			r5 += input / j;

		std::cout<< r5 << "\n";
	}

	return 0;
}