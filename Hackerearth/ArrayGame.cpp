https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/arraygame/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n ,m, i , j, sum=0;
    cin>>n>>m;
    ll a[n] , b[m];
    ll mid =0;
    for(i=0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    for(i=0 ; i<m ;i++)
    {
        cin>>b[i];
    }
    sort(a , a+n);
    sort(b , b+m);
    for(i=0 , j=m-1 ; i<n and j>=0 ; i++ , j--)
    {
        if(a[i] < b[j])
        sum+=abs(a[i] - b[j]);
    }
    cout<<sum<<endl;
}
