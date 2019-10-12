#include <iostream>
using namespace std;
unsigned long long int facto(long int n,unsigned long long int M[])
{
if(n==1)
return 1;
if(M[n])
return M[n];
else
{
M[n]=(n*facto(n-1,M))%(1000000007);
return M[n];
}
}
int main()
{
long int test,n,i,j;
unsigned long long int fact,M[1000001]={0};
cin>>test;
while(test--)
{
cin>>n;
fact = facto(n,M);
cout<<(3*fact+3)%(1000000007)<<endl;
}
return 0;
}

