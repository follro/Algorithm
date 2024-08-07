

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr['z' - 'a'+1] = {0};
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		++arr[s[i] - 'a'];
	}

	for (auto a : arr)	cout << a << " ";
   
}

