#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long

vector <int> adj[1003];
bool visited[1003];
int c = 0;

void dfs(int s,int* counter) {
        visited[s] = true;
        (*counter)++;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
        {
             dfs(adj[s][i],counter);
        }
    }
}
    void initialize() {
        for(int i = 0;i < 10003;++i)
         visited[i] = false;
    }

int main()
{
 int n,m,k,i,j;
 cin >> n >> m >> k;
 int u[m],v[m];
 int g[k],co[k];
 ull ans = 0;
 int flag;
 int sum = 0;
 for(i=0;i<k;i++)
  cin >> g[i];

 for(i=0;i<m;i++)
 {cin >> u[i] >> v[i];
  adj[u[i]].push_back(v[i]);
  adj[v[i]].push_back(u[i]);
 }
 int counter;
 for(i=0;i<k;i++)
 {   counter = 0;
    // cout << "component " << i << "\n";
      dfs(g[i],&counter);
     //cout << "counter " << counter << "\n";
     co[i] = counter;
     sum += co[i];
 }
 int maximum = co[0];
 int temp = 0;
 //cout << "flag " << "\n";
 for(i=1;i<k;i++)
 {
     if(co[i] > maximum)
     {
      maximum = co[i];
      temp = i;
     }
 }
   /*cout << "flag " << "\n";
   cout << "temp" << temp << "\n";
   cout << "sum " << sum << "\n"; */
   co[temp] += max(0,(n-sum));
  // cout << "co[temp] " << co[temp] << "\n";
    for(i=0;i<k;i++)
   {
       ans += co[i]*(co[i]-1)/2;
   }
   cout << ans - m << "\n";
   return 0;
 }
