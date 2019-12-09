//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/kth-character-2/

#include<bits/stdc++.h>
using namespace std;
int c[1000000][26]={};
int main()
{
    int n ,q, i ,j , l , r, k;
    cin>>n>>q;
    string s;
    cin>>s;
    for(i=0 ; i<s.length() ; i++)
    {
        for(j=0 ; j<26 ; j++)
        {
            if(s[i]==j + 'a')
            {
                c[i][j]=1;
            }
            if(i!=0)
            c[i][j]+=c[i-1 ][j];
        }
    }
    for(i=0 ; i<s.length() ; i++)
    {
        for(j=0 ; j<26 ; j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
    }
    while(q--)
    {
        cin>>l>>r>>k;
        l-- ;
        r--; 
        for(i=0 ; i<26 ; i++)
        {
            k = k - c[r][i];
            if(l > 0){
                k += c[l - 1][i];
            }
            if(k<=0){
                cout<<char( i + 97)<<endl;
                break;
            }
        }
        
    }
}
