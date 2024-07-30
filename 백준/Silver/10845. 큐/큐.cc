#include <iostream>

using namespace std;

struct MyQueue
{
	int x;
	MyQueue* mfront; // 현재 큐의 앞에
	static MyQueue* mhead; // 제일 앞
	static MyQueue* mback; // 제일 뒤
	static int size;
};

int MyQueue::size = 0;
MyQueue* MyQueue::mhead = nullptr;
MyQueue* MyQueue::mback = nullptr;

int qEmpty();
void qPush(int x);
int qPop();
int qSize();
int qFront();
int qBack();

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		string input;
		int x = 0;
		cin >> input;

		if (input == "push")
		{
			cin >> x;
			qPush(x);
		}
		else if (input == "pop")
		{
			cout << qPop() << "\n";
		}
		else if (input == "size")
		{
			cout << qSize() << "\n";
		}
		else if (input == "empty")
		{
			cout << qEmpty() << "\n";
		}
		else if (input == "front")
		{
			cout << qFront() << "\n";
		}
		else if (input == "back")
		{
			cout << qBack() << "\n";
		}
	}

	
	return 0;
}

// 비었는지 확인
int qEmpty()
{
	if ((MyQueue::size == 0) && (MyQueue::mhead == nullptr) && (MyQueue::mback == nullptr))
	{
		return 1;
	}

	return 0;
}

//제일 뒤에 푸쉬
void qPush(int x)
{
	
	MyQueue* newData = new MyQueue;
	newData->x = x;
	newData->mfront = MyQueue::mback;
	MyQueue::mback = newData;

	if (MyQueue::mhead == nullptr)
	{
		MyQueue::mhead = MyQueue::mback;
	}

	++MyQueue::size;
}

int qPop()
{
	int popData;
	if (MyQueue::mhead == nullptr && MyQueue::mback == nullptr) return -1;
	if (MyQueue::mhead == MyQueue::mback) 
	{ 
		popData = MyQueue::mhead->x;
		MyQueue::mhead = MyQueue::mback = nullptr; 
		MyQueue::size--;
		return popData;
	}

	MyQueue* popUp = MyQueue::mback;

	while (popUp->mfront != MyQueue::mhead)
	{
		popUp = popUp->mfront;
	}

	if (MyQueue::mhead != nullptr)
	{
		popData = MyQueue::mhead->x;
		delete MyQueue::mhead;
	}
	else
		popData = 0;

	popUp->mfront = nullptr;
	MyQueue::mhead = popUp;

	MyQueue::size--;

	return popData;
}

int qSize()
{
	return MyQueue::size;
}

int qFront()
{
	if (MyQueue::mhead == nullptr) return -1;
	return MyQueue::mhead->x;
}

int qBack()
{
	if (MyQueue::mback == nullptr) return -1;
	return MyQueue::mback->x;
}
