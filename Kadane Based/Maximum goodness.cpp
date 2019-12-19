//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximum-goodness/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n , i , a[10000];
    cin>>n;
    for(i=0 ; i<n ; i++)
    {
        cin>>a[i];
        if(a[i]==0)
            a[i]=-1;
    }
    int cur = a[0] , max = cur , end=0 , start=0 , pre=0;
    for(i=1; i<n ; i++)
    {
        cur +=a[i];
        if(cur>=max)
        {
            max = cur;
            start = pre;
            end = i+1;
        }
        if(cur<0)
        {
            cur=0;
            pre = i+1;
        }
    }
    cout<<start<<" "<<end<<endl;
    cout<<end - start<<endl;
    
}
