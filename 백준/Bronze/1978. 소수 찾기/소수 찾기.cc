#include <iostream>
#include <vector>

int main()
{
	int N = 0, num = 0, count = 0;
	const int MaxCount = 1000;
	std::cin >> N;
	std::vector<bool> isPrimes(MaxCount + 1, true);

	isPrimes[0] = isPrimes[1] = false;

	for (int i = 2; i * i <= MaxCount; i++)
	{
		if (isPrimes[i])
		{
			for (int j = i * i; j <= MaxCount; j += i)
				isPrimes[j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cin >> num;
		if (isPrimes[num])
			count++;
	}

	std::cout << count;

	return 0;
}