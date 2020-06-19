//https://codeforces.com/contest/1368/problem/D

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Int int32_t
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1l)
const int M = 1000000007;
const int N=3e5+5;
const int INF = 1e9+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
void solve(){
    int n;
    cin >> n;
    int a[n];
    int bits[22]={};
    for(int i=0 ; i<n; i++){
        cin >> a[i];
        for(int j=0 ; j<=20 ; j++){
            if(a[i]&(1LL<<j)) bits[j]++;
        }
    }
    int sum =0;
    for(int i=0 ; i<n ;i++){
        int cur=0;
        for(int j=0 ; j<=20; j++){
            if(bits[j]){
                cur|=(1LL<<j);
                bits[j]--;
            }
        }
        sum+=cur*cur;
    }
    cout << sum << endl;
}


signed main(){
    FAST;
    //TODO: check test cases.
    int tc=1;
//    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}

/* Extra Cares
* 1)In graphs or dp problems sometimes long long creates MLE.
* 2)Check whether int to long long typecasting is commented or not?
* 3)Check overflows.
*/
