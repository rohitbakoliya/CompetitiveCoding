#include<bits/stdc++.h>

using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
long q;
cin >> q;
unsigned long long c,m,x,mini,team,maxi;
while(q--)
{
  cin >> c >> m >> x;
  mini = min(c,m);
  if(x >= mini)
  cout << mini << "\n";
  else
   {
     team = x;
     c = c - x;
     m = m - x;
     mini = min(c,m);
     maxi = max(c,m);
     if(c == m || mini >= (int)(maxi/2))
        team +=  (int)((c + m)/3);
     if(mini < (int)(maxi/2))
        team += min(c,m);
     cout << team << "\n";
   }
   }
return 0;
}
