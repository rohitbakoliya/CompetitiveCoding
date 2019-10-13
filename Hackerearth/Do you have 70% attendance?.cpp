/* 

    https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/attendance-70-3369f484/description/
    
    */
    
    #include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;
    cin>>s;
    float sq =0;
    int flag = 0;
    for(int n=1 ; n<=100 ; n++)
    {
        bool flag = true;
        if(((int)log10(n*n)+1)==s.length())
        {
            string str = to_string(n*n);
            for(i=0; i<s.length() ; i++)
            {
                if(s[i]=='*');
                else if(s[i]!=str[i])
                {
                    flag = false;
                }
            }
            if(flag)
            {
                cout<<n<<endl;
                return 0;
            }
        }
    }
    if(!flag)
    {
        cout<<0<<endl;
    }
    
}
