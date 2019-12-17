#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n , i , j ;
    cin>>n;
    ll a[1000000];
    for(i=0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    set< ll > s;
    ll ans=0;
    ll f[1000000]={};
    s.insert(a[n-1]);
    for(i=n-2 ; i>=0 ; i--)
    {
        f[i] = s.size();
        s.insert(a[i]);
    }
    s.clear();
    for(i=0 ; i<n ; i++)
    {
        if(s.count(a[i])==0)
        {
            ans+=f[i];
        }
        s.insert(a[i]);
    }
    cout<<ans<<endl;


	return 0;
}
