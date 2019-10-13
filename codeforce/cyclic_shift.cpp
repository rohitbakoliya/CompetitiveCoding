#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
  string s;
  cin >> s;
  vector <std::string> new_string;
  int n = s.length();
  int v = n;
  int count = 1;
  new_string.push_back(s);
  while(v--)
  {
    char last = s[n-1];
    for(int i=(n-1);i>0;i--)
    s[i] = s[i-1];

       s[0] = last;
    // cout << s << "\n";
     int flag = 0;
     for(int i=0;i<new_string.size();i++)
     {
       if(s == new_string[i])
       {flag = 1;
        break;
       }
     }
      if(flag == 0)
      {
       new_string.push_back(s);
       count++;
      }
  }
   cout << count << "\n";
   return 0;
}
