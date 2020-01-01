//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/little-monk-and-swaps/description/

//We could also do level order traversal and add the elements to a queue.
//Compare the indices at 2*i and 2*i+1. If they do not satisfy the properties of a bst, 
//then we could increase the count of the swaps by 1

//see editoral



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define F first
#define S second
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debug2(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;
#define PI acos(-1)
const int M = 1000000007;
const int N=3e5+5;
double phi = 1.61803398875;
int powmod(int x,int n){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int powmod(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
vector<int> bst;

void inorder(int* a, int start , int end)
{
    if(start <= end)
    {
        inorder(a , 2*start , end);
        bst.push_back(a[start]);
        inorder(a , 2*start+1 , end);
    }
}
int32_t main()
{
    int n , i ,j;
    cin>>n;
    int *a = new int[n+1];
    for(i=1 ; i<=n ; i++)
    {
        cin>>a[i];
    }
    bst.push_back(0);
    inorder(a , 1 , n);
    int cnt=0;
    // for(auto x : bst){
    //     cout<<x<<" ";
    // }
    vector< pair< int , int > > v;
    v.push_back({0 ,0});
    for(i=1 ; i<=n ; i++)
    {
        v.push_back({bst[i] , i});
    }
//minimun number of swaps requried to make array sorted.
    sort(v.begin() , v.end());
    for(i=1 ; i<=n ; i++)
    {
        if(v[i].second==i) continue;
        else
        {
            swap(v[i].first ,v[v[i].second].first);
            swap(v[i].second , v[v[i].second].second);
        }
        if(i!=v[i].second)
        --i;
        cnt++;
    }
    cout<<cnt<<endl;
}


