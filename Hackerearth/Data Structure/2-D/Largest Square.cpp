///https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/largest-square-3d7a938a/


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
int powmod(int x,int n){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int powmod(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
 
int32_t main()
{
    int n, i , j;
    cin>>n;
    map< int , set< int > > mp;
    while(n--)
    {
        cin>>i>>j;
        mp[i].insert(j);
    }
    int maxSide = 0;
    pair< int , int > ans;
    ans = {0 , 0 };
    for(auto it=mp.begin() ; it!=mp.end() ;it++)
    {
        int x1 = it->first;
        for(auto y1=mp[x1].begin() ; y1!=mp[x1].end() ; y1++)
        {
            for(auto y2=next(y1) ; y2!=mp[x1].end(); y2++)
            {
                int side = *y2 - *y1;
                if(side < maxSide || (side==maxSide && ans.second <= *y1)) continue;
                
                int x2 = x1 + side;
                
                if(mp[x2].count(*y1)==1 && mp[x2].count(*y2))
                {
                    maxSide = side ;
                    ans = { x1 , *y1 };
                }
            }
        }
    }
    if(maxSide!=0)
    {
        cout<<ans.first<< " "<<ans.second<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    
}
 
 
