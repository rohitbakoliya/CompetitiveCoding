/*
*  problem link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-gcd-1-15/editorial/
*  solution link - https://github.com/nhannguyen95/algorithm/blob/master/hackerearth-GCDSUM.cpp
*  resources - https://en.wikipedia.org/wiki/Pillai%27s_arithmetical_function
*            - http://codeforces.com/blog/entry/8989
*            - http://www.geeksforgeeks.org/eulers-totient-function/
*/

/*

Compute function first computes Euler Totient function Phi(n) for all n (1 <= n<= 5*10^5) and use these Phi(n) to generate gcd-sum for n.

What we need to find is FX[i] for all 1<= i <= n; where FX[i] = GCD(1, i) + GCD(2, i)+.....+GCD(n, n).

function FX[i] is known as Pillai's arithmatical function(gcd-sum function).

Pillai's function can be written in terms of Euler Totient function (Phi function).
............__
FX[i] = \ d * Phi[n/d] where d are divisors(factors) of n.
............/__
...........d|n

Euler Totient function Phi[n] is defined as the count of numbers form 1 - n which are co-primes of n.
phi[n] for any n can be calculated using Totient product formula:

phi[n] = n*(1 - 1/p1)*(1 - 1/p2)*(1 - 1/p3)*....*(1 - 1/pi) ; where pi are prime factors of n*

......................__
phi[n] = n * || (1 - 1/p) ; p are primefactors of n.
......................p|n

......................__
phi[n] = n * || (n - n/p) ; p are primefactors of n.
......................p|n
We will be using the above formula to generate all Phi form 1 - n using sieve method.

Let us say eulerPhi[i] be the value of phi(i). Assign initially all the values of eulerPhi[i] to be i. Then for every prime p, for all multiples of p, we will multiply value of eulerPhi[i] by (1 - 1/p) as per the formula. multiplying eulerPhi[i] by (1 - 1/p) is exactly equal to eulerPhi[i] -= (eulerPhi[i] / p).

//sieve for finding phi[i] 1<= i <= n

for(i = 1; i <= n; i++)
eulerPhi[i] = i;

for(i = 2; i <= n; i++){
if(eulerPhi[i] == i){ // i was never encountered before, hence i is prime number(similar concept as shieve method of generating primes)
for(j = i; j <= n; j += i) //for every multipe of the prime i
eulerPhi[j] -= eulerPhi[j] / i;
}
}

now once we have Phi[i] for all 1 <= i <= n; we can use the above mentioned formula for generating gcd-sum.
............__
FX[i] = \ d * Phi[n/d] where d are divisors(factors) of n.
............/__
...........d|n

This also we would generate using shieve method.
Let us say pillai[i] be the gcd-sum of i. Initially assing all pillai[i] as 0. Then, for every divisor of i we add d * Phi[n/d] to pillai[i].

//shieve for gcd-sum form 1 to n
for(i = 1; i <=n; i++)
pillai[i] = 0;
for(i = 1; i <= n; i++){
for(j = i; j <= n; j += i) // i would be divisor for all j
pillai[j] += i * Phi[j/i];
}

Now we can use pillai[] as a lookup table for finding gcd-sum.
*/


///solution start from here

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
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
const int N=5e5+5;
const int R = 1e6 + 7;
int phi[N] , phillai[N] ,BIT[R] , a[R];
void findPhi()
{
    for(int i=1 ; i<=N ; i++)phi[i]=i;
    for(int i=2 ; i<=N ; i++)
    {
        if(phi[i]==i)//prime number
        {
            for(int j=i ; j<=N ; j+=i)
            {
                phi[j] =(phi[j]%M - (phi[j]/i)%M + M)%M;
            }
        }
    }
}
void findPhillai()
{
    for(int i=0 ; i<=N ; i++)
        phillai[i]=0;
    for(int i=1 ; i<=N ; i++)
    {
        for(int j=i ; j<=N ; j+=i)
        {
            phillai[j]=(phillai[j]%M + (i%M*phi[j/i]%M)%M)%M;
        }
    }
}
void update(int x, int val , int n)
{
    for(; x <= n; x += x&-x)
    {
        BIT[x]= (BIT[x]%M +val%M)%M;
    }
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
    {
        sum = (sum%M + BIT[x]%M)%M;
    }
     return sum%M;
}


signed main()
{
    memset(phillai , 0 ,  sizeof(phillai));
    findPhi();
    findPhillai();
    memset(BIT , 0 ,  sizeof(BIT));
    int n, i;
    cin>>n;
    for(i=1 ; i<=n ; i++)
    {
        cin>>a[i];
        update(i , phillai[a[i]] , n);
    }
    int q;
    cin>>q;
    while(--q>=0)
    {
        char c; int x , y;
        cin>>c>>x>>y;
        if(c=='U')
        {
            update(x , (phillai[y]%M-phillai[a[x]]%M + M)%M , n);
            a[x]=y%M;
        }
        else
        {
            int ans = query(y)%M;
            if(x>0)
            {
                ans= (ans%M - query(x-1)%M + M)%M;
            }
            cout<<ans%M<<"\n";
        }
    }
    
    
}


