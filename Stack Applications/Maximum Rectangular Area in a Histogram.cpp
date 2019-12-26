#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	
	ll t ,n ,i , j , k;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    ll a[n];
	    for(i=0 ; i<n ; i++)
	    {
	        cin>>a[i];
	    }
	    stack< ll > s;// non decreasing sequence
	    ll mxArea = INT_MIN;
	    for(i=0 ; i<n ;)
	    {
	        if(s.empty() || a[i]>=a[s.top()])
	        {
	            s.push(i++);
	        }
	        else{
	            ll tp = s.top();
	            s.pop();
	            ll area =0;
	            if(s.empty())
	            area = a[tp]*i;
	            else
	            area = a[tp]*(i - s.top() - 1);
	            
	            if(area > mxArea)
	            mxArea = area;
	        }
	        
	    }
	    while(!s.empty())
	    {
	        ll tp = s.top();
	            s.pop();
	            ll area =0;
	            if(s.empty())
	            area = a[tp]*i;
	            else
	            area = a[tp]*(i - s.top() - 1);
	            
	            if(area > mxArea)
	            mxArea = area;
	    }
	    cout<<mxArea<<endl;
	}

}
