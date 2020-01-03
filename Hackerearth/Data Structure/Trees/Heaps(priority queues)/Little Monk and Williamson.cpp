//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-williamson/description/
/*
Detailed Explanation:
The question asks us to find deal with largest and smallest numbers in queries of type 2,3 and 4. Since priority queue can be either in increasing order or decreasing, we need to maintain two priority queues for this question. Let l be the priority queue containing elements in increasing order and h in decreasing order. As we have to deal with frequency of elements, we also need to maintain an array f for that purpose. Let's deal with each type of query one by one :

Push x: This is the simplest one, we just need to insert the input element into both h and l and increase the frequency of that element by 1. That is, f[element]  is incremented by 1.

CountHigh: If h is empty, we will print -1 as there are no elements in the array presently. Else we print the frequency of top element of h.

CountLow: If l is empty, we will print -1 else we print the frequency of top element of l.

Diff: This is where we need to delete element(s) from the two priority queues. First we check if any of the priority queues is empty, we print -1.
Else we take top element of h and l , and find their difference. If the two elements are the same, we decrement its frequency by 1, else we decrement frequency of both the elements by 1. Then , we pop elements from h and l.

Say we had two different elements v1(smaller) and v2(larger) from above step. We know both are present in both the queues, but we are deleting only  v2 from h and v1 from l. Queue h still contains an instance of v1 and similarly, l still contains an instance of v2. But they should ideally get deleted from the queue as per the question. How should we do it?

For achieving this, in each query, we keep popping elements from the priority queue until the queue is non empty and frequency of top element is zero. This we do for both h and l. This makes sure that we don't have any unwanted values in the queues.
*/


#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const int ma = 1e5+5;
priority_queue <int> high;
priority_queue <int, std::vector<int>, std::greater<int> > low;
int fre[ma];
int main()
{
  //freopen("i.txt","r",stdin);
  //freopen("o1.txt","w",stdout);
  int q;
  cin>>q;
  int x;
  string st;
  for(int i=0;i<q;i++)
  {
   cin>>st;
   if(st[0]=='C' and st[5]=='H')
   {
      while(high.size() and fre[high.top()]==0)
      {
        high.pop();
      }
      if(high.size())
      cout<<fre[high.top()]<<endl;
      else
      cout<<"-1"<<endl;
   }
   else if(st[0]=='C' and st[5]=='L')
   {
     while(low.size() and fre[low.top()]==0)
      {
        low.pop();
      }
      if(low.size())
      cout<<fre[low.top()]<<endl;
      else
      cout<<-1<<endl;
   }
   else if(st[0]=='P')
   {
    cin>>x;
    high.push(x);
    low.push(x);
    fre[x]++;
   }
   else
   {
      while(high.size() and fre[high.top()]==0)
      {
        high.pop();
      }
      while(low.size() and fre[low.top()]==0)
      {
        low.pop();
      }
      if(high.size() and low.size())
      {
       // cout<<i<<" "<<high.top()<<" "<<low.top()<<endl;
        cout<<high.top()-low.top()<<endl;
        if(high.top() == low.top())
        {
          fre[high.top()]--;
        }
        else
        {
          fre[high.top()]--;
          fre[low.top()]--;
        }
        high.pop();
        low.pop();
      }
      else
        cout<<"-1"<<endl;
    }
  }
  return 0;
}


//using maps


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);

#define pb push_back
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define F first
#define S second
#define f(i , a , b) for(i=a ; i<b ; i++)
#define fe(i , a , b) for( i=a ; i<=b ; i++)
#define fr( i , a , b) for( i=a ; i>b ; i--)
#define fre( i , a , b) for( i=a ; i>=b ; i--)

#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debug2(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;

#define PI acos(-1)
const int M = 1000000007;
const int N=3e5+5;
double phi = 1.61803398875;
int powmod(int x,int n){int result=1;while(n>0){if(n % 2 ==1)
result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int powmod(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)
result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
signed main()
{
    map< int , int > mp;
    int q , i , j, score;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        if(s=="CountHigh")
        {
            if(mp.empty())
            {
                cout<<-1<<"\n";
            }
            else
            {
                auto it = mp.rbegin();
                cout<<it->second<<"\n";
            }
        }
        else if(s=="Push")
        {
            cin>>score;
            mp[score]++;
        }
        else if(s=="Diff")
        {
            if(mp.size()==0){
                cout<<-1<<"\n";
            }
            else if(mp.size()==1)
            {
                auto it = mp.begin();
                if(mp[it->first]==1)
                {
                    mp.erase(it);
                }
                else
                {
                    mp[it->first]--;
                }
                cout<<0<<"\n";
            }
            else{
                    auto it = mp.begin();
                    auto rit = mp.end();
                    rit--;
                    cout<<rit->first - it->first<<"\n";
                    if(mp[it->first]==1)
                    {
                        mp.erase(it);
                    }
                    else
                    {
                        mp[it->first]--;
                    }
                    
                    if(mp[rit->first]==1)
                    {
                        mp.erase(rit);
                    }
                    else
                    {
                        mp[rit->first]--;
                    }
                    
                    
                }
        }
        else
        {
            if(mp.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                auto x = mp.begin();
                cout<<x->second<<"\n";
            }
        }
    }
}


