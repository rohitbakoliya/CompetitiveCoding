//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/hostel-visit/description/


//solution using priority queues 

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli rocketDistance(lli x,lli y){
    return x*x+y*y;
}

int main(){
    lli x,y,q,k,type;
    priority_queue<lli> pq;
    cin>>q>>k;
    for(lli i=0;i<q;i++){
        cin>>type;
        if (type == 1){
            cin>>x>>y;
            if (pq.size() == k){
                if (rocketDistance(x,y) < pq.top() ){
                    pq.pop();
                    pq.push(rocketDistance(x,y));
                }
            }
            else{
                pq.push(rocketDistance(x,y));
            }
        }
        else{
            cout<<pq.top()<<endl;
        }
    }
    return 0;
}



//solution using sets

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n , k , x , y, i  , j , t;
    cin>>n>>k;
    multiset<int> s;
    while(n--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            s.insert(x*x + y*y);
        }
        else
        {
            auto it = s.begin();
            for(i=1 ; i<k ; i++)
            it++;
            cout<<*it<<"\n";
        }
    }
}
