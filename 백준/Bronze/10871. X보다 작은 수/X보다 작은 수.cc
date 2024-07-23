
#include <iostream>

int main()
{
	int N, X;
	
	std::cin >> N >> X;

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		std::cin >> A[i];

	for (int i = 0; i < N; i++)
	{
		if (X > A[i]) std::cout << A[i] << " ";
	}

	delete[] A;
}

