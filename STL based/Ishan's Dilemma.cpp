//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/ishans-dilemma/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t , n ,i;
    cin>>t;
    while(t--)
    {
        int c=0 , mx=-1 , v=0;
        cin>>n;
        map< int , int > mp;
        //initially diff is zero 
        mp[0] = -1;
        for(i=0 ; i<n ; i++)
        {
            char chr;
            cin>>chr;
            if(chr=='c')
                c++;
            else
                v++;
            if(mp.find(c-v)!=mp.end())
                mx = max(mx , i - mp[(c - v)]);
            else
                mp[(c - v)] = i;
        }
        if(mx==-1)
        cout<<0<<endl;
        else
        cout<<mx<<endl;
    }
}
