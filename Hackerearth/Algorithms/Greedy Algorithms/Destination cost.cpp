//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/destination-cost-2b27f15b/description/


#include<bits/stdc++.h>
using namespace std;
#define sz(c) (int)(c).size()
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define all(c) c.begin(),c.end()
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
int powmod(int x,int n){int result=1;while(n>0){if(n % 2 ==1)
result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int powmod(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)
result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}

signed main()
{
    int n , i ,j;
    cin>>n;
    vector< int > c(n) , b(n), bus , car;
    for(auto &x : c){
        cin>>x;
    }
    for(auto &x : b){
        cin>>x;
    }
    int ans=0;
    for(i=0 ; i<sz(c) ; i++)
    {
        if(c[i] < b[i])
        {
            ans+=c[i];
            car.pb(b[i] - c[i]);
        }
        else{
            ans+=b[i];
            bus.pb(c[i]-b[i]);
        }
    }
    if(abs(sz(bus) - sz(car))<=1){
        cout<<ans<<"\n";
    }
    else{
        int diff = abs(sz(bus) - sz(car))/2;
        if(sz(bus) > sz(car))
        {
            sort(all(bus));
            for(i=0 ; i<diff ; i++){
                ans+=bus[i];
            }
        }
        else
        {
            sort(all(car));
            for(i=0 ; i<diff ; i++){
                ans+=car[i];
            }
        }
        cout<<ans<<"\n";
    }
    
}


