#include<iostream>
#include<queue>

using namespace std;

vector<int> v[10];
int level[10];
bool visited[10];

void initialize()
{
  for(int i=0;i<10;i++)
  visited[i] = false;
}

void bfs(int s)
{
 queue<int>q;
 q.push(s);
 visited[s] = true;
 level[s] = 0;

 while(!q.empty())
 {
  int p = q.front();
  q.pop();

  for(int i=0;i<v[p].size();i++)
  {
    if(visited[v[p][i]] == false)
    {
      q.push(v[p][i]);
      level[v[p][i]] = level[p]+1;
      visited[v[p][i]] = true;
      cout << "level of " << v[p][i] << " = " << level[v[p][i]] << "\n";
    }
  }
 }
}
int main()
{
int node,edges,x,y;
  cin >> node >> edges;
  for(int i=1;i<=edges;i++)
  {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  initialize();
  bfs(0);
}
