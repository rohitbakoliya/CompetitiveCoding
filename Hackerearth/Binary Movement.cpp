/* https://www.geeksforgeeks.org/constant-time-range-add-operation-array/ */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, i , j ,sum=0, l, r ;
    cin>>n;
    int a[1000001];
    for(i=1 ; i<=n ; i++)
    {
        cin>>a[i];
    }
    cin>>q;
    int ans[1000001]={};
    while(q--)
    {
        cin>>l>>r;
        ans[r+1]--;
        ans[l]++;
    }
    for(i=2 ; i<=n ; i++)
    ans[i]+=ans[i-1];
   
    for(i=1 ;i<=n ;i++)
    {
        if(ans[i]%2!=0) // ans[i] is odd => it(a[i])  occurs in queries odd times i.e overlaping odd times => bit has to be flip
        {
            if(a[i]==1)
            a[i]=0;
            else
            a[i]=1;
        }
    }
    int cnt = count(a+1 , a+n+1 , 1);
    cout<<cnt<<endl;
    for(i=1 ; i<=n ;i++)
    cout<<a[i]<<" ";
}
