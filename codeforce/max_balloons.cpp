#include<iostream>
using namespace std;
int swap(int *a,int *b)
 {
     int temp;
     temp=*a;
     *a=*b;
     *b=temp;
 }
int main()
{
    int t,i,j,balloons=0;
    cin >> t;   // taking the number of balloons
      int a[t];
 for(i=0;i<t;i++)
     cin >> a[i];
  for(i=(t-2);i>=1;i--)
     {
         balloons = balloons + (a[i]*a[i+1]*a[i-1]);      // doing the task except for first and last element of array
         swap(a[i],a[i+1]);                // then swaping the number with the number after it, which will be equivalent to omit that balloon

     }
      balloons = balloons + (a[0]*a[1]) + a[1];

      cout << balloons << "\n";
      return 0;
}
