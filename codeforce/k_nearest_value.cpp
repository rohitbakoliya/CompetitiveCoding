#include <iostream>
#include <queue>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void print_k_closest(int arr[],int n,int x,int k)
{
  priority_queue<pair<int,int> >pq;
  for(int i=0;i<k;i++)
   pq.push({abs(arr[i]-x),i});

   for(int i=k;i<n;i++)
   {
       int diff = abs(arr[i] - x);
       if(diff > pq.top().first)
       continue;
       else
       {pq.pop();
        pq.push({ diff,i });
       }
   }
   while(!pq.empty())
   {
       cout << arr[pq.top().second] << " ";
       pq.pop();
   }
}

int main() {
	int arr[] = {10,12,15,23,45,-1,5,6,8,19,14,16,20};
	int x=13,k=5;
	int n= sizeof(arr)/sizeof(arr[0]);
	print_k_closest(arr,n,x,k);
	return 0;
}
