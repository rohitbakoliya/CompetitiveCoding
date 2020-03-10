//https://leetcode.com/contest/weekly-contest-178/problems/rank-teams-by-votes/

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int len = votes[0].size();
        int i , j , k;
        vector< vector< int > > lookup (26 , vector< int >(27));
        set< char > s;
        for(i=0 ; i<n ; i++)
        {
            for(j=0 ; j<len ; j++)
            {
                lookup[votes[i][j]-'A'][j]++;
                s.insert(votes[i][j]);
            }
        }
        for(i=0 ; i<26 ; i++)
        {
            lookup[i][26]=i;
        }
        sort(lookup.begin(), lookup.end() , [](auto x , auto y )
         {
             for(int i=0 ; i<26 ; i++)
             {
                 if(x[i]!=y[i]) return x[i] > y[i];
               
             }
              return x[26] < y[26];
         });
        string ans;
        for(i=0 ; i<26 ; i++)
        {
            if(s.find('A' + lookup[i][26])!=s.end())
                ans+=char('A' + lookup[i][26]);
        }
        
        return ans;
    }
};
