#include <iostream>
#include <vector>

int main()
{
	int N, M, answer = 0;
	std::cin >> N >> M;
	std::vector<int> cards(N);
	for (int i =0 ; i < N; i++)
		std::cin >> cards[i];

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			int value1 = cards[i] + cards[j];
			if (value1 > M)
				continue;

			for (int q = j + 1; q < N; q++)
			{
				int value2 = value1 + cards[q];
				if (value2 > M)
					continue;

				if (value2 > answer)
					answer = value2;
			}
		}
	}

	std::cout << answer;
	return 0;
}