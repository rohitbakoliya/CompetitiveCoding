//https://leetcode.com/problems/subarray-sum-equals-k/submissions/

class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        unordered_map< int , int > mp;
        mp[0] = 1;
        int currSum = 0 , res = 0;
        for(int i=0 ; i<n ; i++) {
            currSum +=v[i];
            res+=mp[currSum - k];
            mp[currSum]++;
        }
        return res;
    }
};
