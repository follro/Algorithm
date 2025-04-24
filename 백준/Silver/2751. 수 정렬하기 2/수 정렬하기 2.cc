#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void merge(std::vector<int>& data, int left, int right);
void mergeSort(std::vector<int>& data, int left, int right);
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> datas(n);

	for (int i = 0; i < n; i++)
		std::cin >> datas[i];

	mergeSort(datas, 0, datas.size()-1);

	for (auto answer : datas)
		std::cout << answer << "\n";

	return 0;
}



void merge(std::vector<int>& data, int left, int right)
{
	std::vector<int> mergeVec;

	int mid = (right + left) / 2;

	int l = left;
	int r = mid + 1;

	while (l <= mid &&  r <= right)
	{
		if (data[l] <= data[r])
			mergeVec.push_back(data[l++]);
		else
			mergeVec.push_back(data[r++]);
	}

	while (l <= mid)
		mergeVec.push_back(data[l++]);

	while (r <= right)
		mergeVec.push_back(data[r++]);


	std::copy(mergeVec.begin(), mergeVec.end(), data.begin() + left);
}


void mergeSort(std::vector<int>& data, int left, int right)
{
	if (left >= right)
		return;

	int mid =  (right + left) / 2;

	mergeSort(data, left, mid);
	mergeSort(data, mid+1, right);
	merge(data, left, right);

}