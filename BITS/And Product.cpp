#include <bits/stdc++.h>

using namespace std;
long andProduct(long a, long b) {
    bitset<32> A(a) , B(b);
    int last = 0;
    for(int i=0 ;i<32 ; i++){
        if(A[i]!=B[i]){
            last = i;
        }
    }
    bitset<32> ans;
    ans.reset();
    for(int i=last+1 ; i<32 ; i++){
        ans[i] = A[i];
    }
    return (long)ans.to_ullong();
}

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        long a , b;
        cin >> a >> b;
        cout << andProduct(a , b)<< "\n";
    }
}


/*
Explanation: 

Let's say a and b are:

a = 26 = 011010
b = 40 = 101000

The leftmost 1 bit of b is to the left of the leftmost 1 bit of a. So, there is a power of 2 that lies between a and b - namely, 32 (100000) which when ANDed with anything before it will result in 0. This will make the final result 0.

However, if a and b were

a = 42 = 101010
b = 57 = 111001

their leftmost 1 bits are aligned (are in the same bit position). If we temporarily ignore this 1 bit in both, we have:

a = 01010
b = 11001

Again there exists a power of 2, namely 16 (10000) that lies between these two sub-values that will eventually zero out the AND product in these bits.

The ANDproduct of the range [101010, 111001] is 100000. In other words, ANDing the range [101010, 111001] is equivalent to preserving the ALL leftmost ALIGNED bits (both 1s and 0s) and zeroing out all bits starting with the first non-aligned bit.

To zero-out all bits starting with the first non-aligned bit, we need to AND these bits with 0s.

To do so, we first a XOR b to get 10011. These bits will have to be zeroed-out. Next, we get the smallest power of 2 larger than this XOR value which happens to be 100000. Subtracting 1, we get 11111, and then finally inverting the bits, we get 11111111111111111111111111100000 (32-bit).

Now, this value ANDed with either A or B will produce the final AND product.
*/
