#include<bits/stdc++.h>
#include<set>

using namespace std;
#define ll long long

int main()
{
 string s;
 cin >> s;
 ll len = s.size();
 set<int>a;
 ll i;
 int t;
 ll q,pos1,pos2;
 char c;
 cin >> q;
 while(q--)
 {
   cin >> t;
   if(t == 1)
   {
     cin >> pos1;
     cin >> c;
     s[pos1-1] = c;
   }
   if(t == 2)
   {
     cin >> pos1 >> pos2;
     for(i=pos1-1;i<pos2;i++)
     a.insert(s[i]);

     cout << a.size() << "\n";
     a.clear();
   }
 }
 return 0;
}
