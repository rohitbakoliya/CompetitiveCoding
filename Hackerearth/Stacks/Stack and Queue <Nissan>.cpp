//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/staque-1-e790a29f/editorial/

//1 solution

#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, k ,i;
    cin>>n>>k;
    int *a = new int[n+1];
    for(i=1; i<=n ; i++)
    {
        cin>>a[i];
    }
    int sum = 0;
    vector< int > f , r;
    for(i=1; i<=k ; i++)
    {
        sum+=a[i];
    }
    int sumA=sum;
    for(i=1 ; i<k; i++)
    {
        sum+=a[n-i+1] - a[k-i+1];
        if(sum >= sumA)
        {
            sumA = sum;
        }
    }
    cout<<sumA;    
}

//2nd 
#include <iostream>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll ans,n,k,i,a[100000],totalsum=0;
    cin>>n>>k;
    k=n-k;
    
    for(i=0;i<n;i++)
    { cin>>a[i];
     totalsum+=a[i];
    }
    
    ll windowsum=0,minsum;
    for(i=1;i<=k;i++)
        windowsum += a[i];
    minsum=windowsum;
    
    for(i=k+1;i<n;i++)
    {
        windowsum = windowsum + a[i] - a[i-k];
        if(minsum>windowsum)
        minsum=windowsum;
    }
    
    cout<<totalsum-minsum;
    
    
}
