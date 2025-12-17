#include<iostream>
#include<vector>

int n;
std::vector<int> sequence;
std::vector<int> bigValueIndex;


void roop(int curIndex,int nextIndex)
{
	if (nextIndex == -1) return;
	if (sequence[curIndex] < sequence[nextIndex])
	{
		bigValueIndex[curIndex] = nextIndex;
		return;
	}

	roop(curIndex, bigValueIndex[nextIndex]);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	std::cin >> n;
	int input;
	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		sequence.push_back(input);
		bigValueIndex.push_back(-1);
	}

	for (int i = n - 2; i >= 0; i--)
		roop(i, i + 1);

	for (auto index : bigValueIndex)
	{
		if (index == -1) std::cout << index << " ";
		else
			std::cout << sequence[index] << " ";
	}

	return 0;
}