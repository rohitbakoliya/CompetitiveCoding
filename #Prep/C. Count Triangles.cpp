//https://codeforces.com/contest/1355/problem/C

//explanation:::
/*
The (intermediate) goal is to calculate the number of (x, y) pairs such that x + y = s for each possible sum s. (It is convenient to keep this counts in a frequency vector indexed by values of s.) For that we can iterate over valid values of x, i.e. from A to B and for each value of x iterate over valid values of y, i.e. from B to C. That enumerates all (x, y) pairs and for each such pair we can add 1 to the count of pairs with sum x+y, thus obtaining the total count of pairs per possible sum value in the end. This has a bad complexity and should be optimized.

Note that for a given value of x, while iterating over y values, we add 1 to frequencies of all sums in the contiguous interval from x + B to x + C. Think of the desired frequency vector as a prefix array, which we will calculate later. And for now let us compute the vector whose prefix sums we are going to calculate to obtain it. To increase an interval in the prefix vector by 1, increase the element at the beginning of the same interval (index x + B), but in the original array, by 1 and decrease the element past the end of the interval (index x + C + 1), also in the original array, by 1. Iterate over values of x and do the same constant time operation just described (+1/-1) for each x. At the end compute the prefix sums vector to obtain the desired frequencies of the sums s.


After calculating frequencies of x+y sums, the z variable comes into play. For the triangle to exist and not be degenerate, x + y > z must be satisfied. (x + z > y and y + z > x are already satisfied due to the increasing order restriction from the condition.)

Now we can either iterate over values of s=x+y and calculate how many z values from the interval C to D are smaller than the given value of s and add the count to the answer. Or we can iterate over values of z from C to D like in the editorial and calculate the number of (x, y) pairs that satisfy x+y > z for the given z, again adding up all counts. To be able to get the number of (x, y) pairs with su


*/
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
int f[1000005];
void solve(){
    int a , b ,c ,d;
    cin >>a >> b >> c >> d;
    memset(f , 0 , sizeof f);
    for(int i=a; i<=b ; i++){
        f[i+b]++;
        f[i+c+1]--;
    }
    for(int i=1 ; i<1000005 ;i++){
        f[i]+=f[i-1];
    }
    int cnt = 0 , ans = 0;
    for(int i=d+1 ; i<1000005; i++){
        cnt+=f[i];
    }
    ans+=cnt;
    for(int i=d-1 ; i>=c ; i--){
        cnt+=f[i+1];
        ans+=cnt;
    }
    cout<< ans << endl;

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



