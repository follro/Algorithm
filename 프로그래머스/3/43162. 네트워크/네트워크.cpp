#include <string>
#include <vector>

using namespace std;

void dfs(const int n, const vector<vector<int>>& computers, 
         int curNode, vector<bool>& visited)
{
    visited[curNode] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(curNode == i || visited[i]) continue;
        if(computers[curNode][i] == 1)
            dfs(n , computers, i, visited);        
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(n, computers, i, visited);
            answer++;
        }   
    }
    return answer;
}