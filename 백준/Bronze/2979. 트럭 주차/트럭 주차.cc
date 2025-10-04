	#include <iostream>
	#include <string>
	#include <vector>
	#define INF 0x7FFFFFFF

	int a, b, c;
	std::vector<int> times(101, 0);

	//방법 1 2중 for문으로 푸는법


	int main()
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
	
		std::cin >> a >> b >> c;
		int result = 0;

		for (int i = 0; i < 3; i++)
		{
			int start = 0, end = 0;

			std::cin >> start >> end;

			for (int i = start; i < end; i++)
				++times[i];
		}


		for (auto k : times)
		{
			switch (k)
			{
			case 1:
				result += a;
				break;
			case 2:
				result += (b * 2);
				break;
			case 3:
				result += (c * 3);
				break;
			
			}
		}

		std::cout << result;
	

	}

