#include <string>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>

class MySet
{
	int s;

public:
	MySet()
	{
		s = 0;
	}

	void add(int x);
	void remove(int x);
	int check(int x);
	void toggle(int x);
	void all();
	void empty();
};


int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int m, x;
	std::string data;
	std::cin >> m;

	MySet* mySet = new MySet();

	for (int i = 0; i < m; i++)
	{
		std::cin >> data;

		if (data == "add")
		{
			std::cin >> x;
			mySet->add(x);
		}
		else if (data == "remove")
		{
			std::cin >> x;
			mySet->remove(x);
		}
		else if (data == "check")
		{
			std::cin >> x;
			std::cout << mySet->check(x) << "\n";
		}
		else if (data == "toggle")
		{
			std::cin >> x;
			mySet->toggle(x);
		}
		else if (data == "all")
			mySet->all();
		else if (data == "empty")
			mySet->empty();

	}


	delete mySet;
	return 0;
}

void MySet::add(int x)
{
   s |= (1 << x);
}

void MySet::remove(int x)
{
	s &= ~(1 << x);
}

int MySet::check(int x)
{
	if ((1 << x) & s)
		return 1;
	return 0;
}

void MySet::toggle(int x)
{
	s ^= (1 << x);
}

void MySet::all()
{
	s = ((1 << 21) - 1) & ~1;
}

void MySet::empty()
{
	s = 0;
}
