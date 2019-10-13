#include<bits/stdc++.h>

using namespace std;

int main()
{
 int n;
 cin >> n;
 int l = 1,i,j;
 for(i=1;i<=n;i++)
 {

    if(i%2 != 0)
    {
     for(j=1;j<=n;j++)
    {
      if(j%2 == 0)
      cout << "B";
      else
      cout << "W";
    }
     }
    if(i%2 == 0)
    {
      if(l%2 != 0)
      {
        for(j=1;j<=n;j++)
        cout << "B";
      }
      else
       for(j=1;j<=n;j++)
       cout << "W";

       l++;
    }
    cout << "\n";
 }
}

