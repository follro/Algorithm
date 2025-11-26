#include<iostream>
#include<string>
#include<algorithm>

int n;

int prevScore[3] = { 0, 0, 0 };
int times[3] = {0, 0, 0};
int team1, team2;
int curTime, prevTime;


int main()
{

	std::cin >> n;
	int num, min, sec;

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d:%d", &num, &min, &sec);
		
		curTime = min * 60 + sec;

		if		(prevScore[1] > prevScore[2])
			team1 += curTime - prevTime;
		else if (prevScore[1] < prevScore[2])
			team2 += curTime - prevTime;

		prevScore[num]++;
		prevTime = curTime;
	}

	if (prevScore[1] > prevScore[2])
		team1 += 48 * 60 - prevTime;
	else if (prevScore[1] < prevScore[2])
		team2 += 48 * 60 - prevTime;

	printf("%02d:%02d\n", team1 / 60, team1 % 60);
	printf("%02d:%02d\n", team2 / 60, team2 % 60);
	return 0;
}