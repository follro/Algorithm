#include <string>
#include <vector>

using namespace std; //음수냐 양수냐 선택이 가능해 
void dfs(const vector<int>& numbers, const int target, int curIndex, int curValue,int& answer)
{
    if(numbers.size() == curIndex)
    {
        if(curValue == target) answer++;
        return;
    }
    dfs(numbers, target, curIndex + 1, curValue + numbers[curIndex], answer);
    dfs(numbers, target, curIndex + 1, curValue - numbers[curIndex], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0,answer);
    return answer;
}