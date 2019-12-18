//hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/mandee-and-his-girlfriend-9a96aabd/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll q , n, i ;
    cin>>n>>q;
    int type , val;
    map< ll , ll > mp;
    mp.clear();
    while(q--)
    {
        cin>>type>>val;
        if(type==1)
        {
            mp[val]=val;
        }
        else
        {
            auto it = mp.lower_bound(val);
            if(it->first==mp.size() && it==mp.end())
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<it->first<<endl;
            }
        }
    }
	return 0;
}
