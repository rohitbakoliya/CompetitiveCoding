//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/haunted/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);

int32_t main()
{
    FAST;
    int n , m, i , j;
    cin>>n>>m;
    unordered_map< int , int > mp;
    priority_queue< pair< int , int >  > f;
    for(i=0 ; i<n ;i++)
    {
        cin>>j;
        mp[j]++;
        f.push({mp[j] , j});
        auto x = f.top();
        cout<<x.second<<" "<<x.first<<"\n";
    }
}


