#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> data;
	int input, i = 9, sum = 0;
	set<int>::iterator sIt; //시작 이터
	set<int>::iterator eIt; //엔드 이터

	while (i-- > 0)
	{
		cin >> input;
		data.insert(input);
		
		sum += input;
	}

	sIt = data.begin();
	eIt = --data.end();
	
	while(sIt != data.end())
	{
		while (eIt != sIt)
		{
			if ((sum - *eIt - *sIt) == 100)
			{
				data.erase(eIt);
				data.erase(sIt);
				for (auto a : data) cout << a << "\n";
				return 0;
			}
			--eIt;
		}

		eIt = --data.end();
		++sIt;
	}


		
	return 0;
}