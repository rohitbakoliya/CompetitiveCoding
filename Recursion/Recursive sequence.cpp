//https://practice.geeksforgeeks.org/problems/recursive-sequence/0


using namespace std;
#define ll long long
ll term(ll cnt , ll start)
{
    if(cnt==0)
    return 1;
    
    return term(--cnt , ++start)*start;
}


ll sol(ll cnt , ll n)
{
    if(cnt==n+1)
        return 0;
    
    ll start = (cnt*cnt - cnt)/2 ;
    
    //here for this sequence nth term is (n*n - n )/2 + 1;
    //but we have to pass one lowered term 
    //because in term function start is incremented before multiplication
    
    return sol(++cnt , n ) + term(cnt-1 , start );
}

int main() {
	ll t ,n ,i ;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<sol(1 , n)<<endl;
	}
	
	return 0;
}
