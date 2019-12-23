Since X, Y and Z are the prime numbers so we have to make the powers of these numbers in prime factorization 
of the numbers in array to be equal. We can't change the power of other prime numbers 
so we can first divide all the numbers by X, Y and Z till they become non divisible by them. 
After this all the numbers must be equal. If they are then answer is "She can" else "She can't"
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t,n,x,y,z;
    cin>>t;
    while(t--){
        cin>>n>>x>>y>>z;
        int b;
        bool flag = 0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            while(a%x==0) a/=x;
            while(a%y==0) a/=y;
            while(a%z==0) a/=z;
            if(i>1&&a!=b){
                flag =1;
            }
            b=a;
        }
        if(!flag){
            cout<<"She can"<<endl;
        } else {
            cout<<"She can't"<<endl;
        }
    }
    return 0;
}
