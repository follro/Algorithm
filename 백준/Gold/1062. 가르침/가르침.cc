#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int n, k;
std::vector<int> a;
int alphabetMask;
const std::string antic = "antic";

int counting(int mask)
{
	int cnt = 0;
	for (int wordMask : a)
	{
		if ( (mask & wordMask) == wordMask)
			cnt++;
	}
	return cnt;
}

int go(int idx, int num, int selected)
{
	if (num < 0) return 0;
	if (idx == 26) return counting(selected);
	//선택한 경우
	int ret = go(idx + 1, num - 1, selected | (1 << idx));
	
	//선택 확정 조건
	for (char c : antic)
		if (idx == c - 'a')
			return ret;

	//선택 안함
	ret = std::max(ret, go(idx + 1, num, selected));
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;
		
		a.push_back(0);
		for (char c : input)
			a[i] |= (1 << (c - 'a'));
	}

	std::cout << go(0, k, 0);

}