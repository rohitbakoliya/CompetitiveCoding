//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/zulu-encounters-a-sequence-problem/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t , n ,i , j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0 ; i<n; i++)
            cin>>a[i];
        int mx=LLONG_MIN;
        int diff = 0;
        for(i=0 ;i<n-1 ; i++)
        {
            if(a[i] <=a[i+1])
            {
                diff +=a[i+1]-a[i];
            }
            else
            {
                if(diff > mx)
                {
                    mx = diff;
                }
                diff =0;
            }
        }
        if(diff > mx)
        {
            mx = diff;
        }
        
        int mmx = LLONG_MIN;
        diff = 0;
        for(i=0 ;i<n-1 ; i++)
        {
            if(a[i] >=a[i+1])
            {
                diff +=a[i] - a[i+1];
            }
            else
            {
                if(diff > mmx)
                {
                    mmx = diff;
                }
                diff =0;
            }
        }
        if(diff > mmx)
        {
            mmx = diff;
        }
        cout<<max(mmx , mx)<<endl;
        
    }
	return 0;
}
