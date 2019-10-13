#include<bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define ll long long

int main()
{
 ll n,k,i,l = 1;
 cin >> n >> k;
 ull id[n],temp;
 deque<ull>q;
 set<ull>s;
 //set<ull>::iterator it;

 for(i=0;i<n;i++)
 {
   cin >> id[i];
   if(l <= k)
   {
     //it = std::find(s.begin(),s.end(),id[i]);
     if(!s.count(id[i]))
     {
     q.push_back(id[i]);
     s.insert(id[i]);
     l++; }
   }
   else
   {
     //it = std::find(s.begin(),s.end(),id[i]);
     if(!s.count(id[i]))
     {
       temp = q.front();
       q.pop_front();
       s.erase(temp);
       q.push_back(id[i]);
       s.insert(id[i]);
     }
   }
 }
  cout << l-1 << "\n";
    while(!q.empty())
    {cout << q.back() << " ";
     q.pop_back();
    }
    return 0;
}
