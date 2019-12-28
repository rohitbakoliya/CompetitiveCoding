//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/the-amazing-race-1/description/



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

int x[1000001];
void solve(int *a , int n )
{
    stack< int > s;
    int i , j;
    for(i=0; i<n; i++)
    {
        while(!s.empty() && a[s.top()]<a[i])
                s.pop();
            
        x[i] = ((s.empty())?(i):(i-s.top()));
        s.push(i);
    }
    return;
}

int32_t main()
{
    int t, n ,i , j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int *a = new int[n];
        for(i=0 ; i<n ; i++)
        {
            cin>>a[i];
        }
        solve(a , n);
        int front[n];
        for(i=0 ; i<n; i++)
        {
            front[i] = x[i];
        }
        reverse(a , a+n);
        solve(a , n);
        reverse(x , x +n);
        int mx = LLONG_MIN, mxin=0;
        for(i=0 ; i<n; i++)
        {
            int temp = ((front[i]%M + x[i]%M)%M*(i+1)%M)%M;
            if(mx < temp)
            {
                mx =temp;
                mxin = i;
            }
        }
        cout<<mxin+1<<endl;
    }
    
}
