#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;

bool sortbysec(const pair<unsigned long long int,unsigned long long int> &a, const pair<unsigned long long int,unsigned long long int> &b)
{
    return (a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,i;
    unsigned long long int a,b,count = 0,temp = 0;
    vector< pair<unsigned long long int, unsigned long long int> >v;
    cout << "start" << "\n";
    for(i=1;i<=n;i++)
    {   cout << "start 1" << "\n";
        cin >> a >> b;
        cout << a << " " << b << "\n";
        v.push_back(make_pair(a,b));
    }
     for(i=0;i<n;i++)
    {   cout << "start" << "\n";
        cout << v[i].first << " " << v[i].second << "\n";
    }
    sort(v.begin(),v.end(),sortbysec);
    for(i=0;i<n;i++)
    {   cout << "start" << "\n";
        cout << v[i].first << " " << v[i].second << "\n";
    }
    for(i=0;i<(n-1);i++)
    {
        if(v[i].first <= v[i+1].first && v[i].second < v[i+1].second)
        {
            count++;
            i++;
        }
        else
         temp++;
    }
    cout << count + (temp/2) << "\n";
    return 0;
}
