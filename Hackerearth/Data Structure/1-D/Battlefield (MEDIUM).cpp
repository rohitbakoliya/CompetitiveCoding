//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/battlefield-13/''
//(really it nice problem )

#include<bits/stdc++.h>
using namespace std;
int solve(string s , int n , char c)
{
    int sumK=0 , mxK=0;
    int ks = count(s.begin() , s.end() , c);
    int i;
    for(i=0 ; i<ks; i++)
    {
        
        if(s[i]==c)
        sumK++;
    }
    mxK = sumK;
    for(i=ks ; i<n ; i++)
    {
        if(s[i]==c)
        sumK++;
        if(s[i-ks]==c)
        sumK--;
        mxK = max(mxK , sumK);
    }
    // cout<<mxK<<" "<<sumK<<endl;
    return ks-mxK;
}
int main()
{
    int t, n ,i , j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        cout<<min(solve(s, n, 'K') , solve(s, n , 'D'))<<endl;

    }
}
