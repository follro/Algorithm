#include<vector>
#include<queue>
using namespace std;
int n, m;
queue<pair<int,int>> q;
int dx[4] = {0 , 1 , 0,  -1};
int dy[4] = {1, 0 , -1 , 0 };

void bfs(vector<vector<int>>& maps, vector<vector<int>>& visited)
{
    visited[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        
        if((curY == (n - 1)) && (curX == (m - 1))) return;

        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            
            if(nextY < 0 || nextY >= n 
               || nextX < 0 || nextX >= m || 
               !maps[nextY][nextX]) continue;
            
            if(!visited[nextY][nextX])
            {
                visited[nextY][nextX] = visited[curY][curX] + 1;
                q.push({nextY, nextX});   
            }
            
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    bfs(maps, visited);
    
    if(visited[n-1][m-1])
        answer = visited[n - 1][m - 1];
    else
        answer = -1;
    
    return answer;
}