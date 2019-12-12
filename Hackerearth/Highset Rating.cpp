//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/highest-rating-f8ead57a/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int m , q , i , j , n , mx=INT_MIN;
    cin>>m>>q>>n;
    long long int a[1010000]={};
    for(i=0 ; i<n ; i++)
    {
        long long int temp, tmp;
        cin>>temp;
        a[temp]++;
        for(j=1; j<=q ; j++)
        {
            tmp = temp +  (j*m);
            a[tmp]++;
            tmp = temp - (j*m);
            if(tmp>0)
            {
                a[tmp]++;
            }
        }
    }
    for(i=1 ; i<=1000001 ; i++)
    {
        if(a[i] > mx)
        mx = a[i];
    }
    cout<<mx<<endl;
    
}
