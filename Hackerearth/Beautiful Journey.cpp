//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/beautiful-journey-1/

#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
{
    int n , i , j;
    cin>>n;
    int a[n];
    for(i=0 ; i<n; i++)
    {
        cin>>a[i];
    }
    int l=1, r=n-2;
    int ls=a[0] , rs=a[n-1];
    while(l <= r)
    {
        if(ls < rs)
        {
            ls+=a[l];
            l++;
        }
        else
        {
            rs+=a[r];
            r--;
        }
    }
    cout<<ls*rs<<endl;

}
