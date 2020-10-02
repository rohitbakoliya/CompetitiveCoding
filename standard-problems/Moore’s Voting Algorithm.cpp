// Moore’s Voting Algorithm
// https://www.geeksforgeeks.org/majority-element/   
// https://practice.geeksforgeeks.org/problems/majority-element/0

/*

Given an array of size N, find the majority element. The majority element is the element that appears more than n/2 times in the given array.

*/








#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x,y,z) cout<<"for "<<#x <<" =  "<<(x)<<" "<<#y<<" = "<<(y)<<" ans is "<<#z<<" "<<(z)<<"\n"; 


int main()
{
    fastio;
    ll i,j,n,m,k;
    t()
    {
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++) cin>>a[i];

        // Finding a Candidate
        ll count=1,maj_index=0;
        for(i=1;i<n;i++)
        {
            if(a[i]==a[maj_index]) count++;
            else count --;
            if(count==0){
                maj_index = i;
                count =1;
            }
        }
        // Check if the element obtained in step 1 is majority element or not.
        count=0;
        for(i=0;i<n;i++) if(a[i]==a[maj_index]) count++;
        
        if(count>n/2) cout<<a[maj_index]<<'\n';
        else cout<<"-1\n";
    }
}
