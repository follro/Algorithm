#include <string>
#include <vector>
#include <queue>
using namespace std;
int len;
int targetIndex;
queue<int> q;

bool IsChangeable(string& cur, string& tar)
{
    int count = 0;
    
    for(int i = 0; i < len; i++)
        if(cur[i] != tar[i])
            count++;
    
    if(count == 1) return true;
    else return false;
}

int bfs(vector<string>& words, vector<int>& visited, string target)
{
    visited[visited.size() -1] = 1;
    q.push(words.size() - 1);
    
    while(!q.empty())
    {
        int curIndex = q.front();
        q.pop();
        
        if(words[curIndex] == target) return visited[curIndex];
        
        for(int nextIndex = 0; nextIndex < words.size(); nextIndex++)
        {
            if(visited[nextIndex]) continue;
            if(IsChangeable(words[curIndex], words[nextIndex]))
            {
                visited[nextIndex] = visited[curIndex] + 1;
                q.push(nextIndex);
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    vector<int> visited(words.size(), 0);
    len = begin.size();
    
    bool isIn = false;
    for(string s: words)
        if(s == target) isIn = true;

    if(isIn)
        answer = bfs(words, visited, target) -1;
    else
        answer = 0;
    
    return answer;
}