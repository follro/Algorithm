#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

int n, m, start;
std::vector<std::set<int>> edges;
std::vector<int>visited;

void bfs(int curNode);
void dfs(int curNode);
void dfsSearch(std::stack<int>& stack);

int main() 
{
    std::cin>> n >> m >> start;
    
    edges.resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        std::cin>> u >> v; 
        edges[u].insert(v);
        edges[v].insert(u);
    }

    dfs(start);
    std::cout << "\n";
    bfs(start);
    return 0;
}

void dfs(int curNode)
{
    visited.clear();
    visited.resize(n + 1, -1);

    std::stack<int> stack;
    stack.push(curNode);
    visited[curNode] = 1;

    dfsSearch(stack);
}

void dfsSearch(std::stack<int>& stack)
{
    int vertex = stack.top();
    stack.pop();
    std::cout << vertex << " ";
    for(int next : edges[vertex])
    {
        if(visited[next] == -1)
        {
            stack.push(next);
            visited[next] = 1;
            dfsSearch(stack);
        }
    }
}

void bfs(int curNode)
{
    visited.clear();
    visited.resize(n + 1, -1);

    std::queue<int> q;
    q.push(curNode);
    visited[curNode] = 1;

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        std::cout << vertex << " ";   
        
        for(int next : edges[vertex])
        {
            if(visited[next] == -1)
                q.push(next);
            visited[next] = 1;
        }
    }

}