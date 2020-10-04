/*
https://www.geeksforgeeks.org/next-greater-element-in-same-order-as-input/
*/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <int> s;
    int a[10000],n,i;

    cin>>n;
    for(i=0;i<n;i++) 
      cin>>a[i];
    
    // iterating from n-1 to 0 
    for(i=n-1;i>=0;i--)
    {
        int current=a[i];
         /*We will pop till we get the  
        greater element on top or stack gets empty*/
        while(!s.empty() && s.top()<=current)
         s.pop();

         /*if stack gots empty means there  
        is no element on right which is greater  
        than the current element. 
        if not empty then the next greater  
        element is on top of stack*/
         if (s.empty())  
            a[i] = -1;          
        else 
            a[i] = s.top();         
  
        s.push(current); 
    }
    for(i=0;i<n;i++)
     cout<<a[i]<<" ";
    

}
