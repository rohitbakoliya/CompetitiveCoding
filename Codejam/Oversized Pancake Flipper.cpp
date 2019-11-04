/***https://code.google.com/codejam/contest/3264486/dashboard  ***/

#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    int t , k;
    cin>>t;
    for (int test = 1; test <= t; test++)
    {
        string s;
        cin >> s>>k;
        int n = s.size(), ans = 0;
        for (int i = 0; i  <= n - k; i++) {
            if (s[i] == '+')
                continue;
            for (int j = i; j < i + k; j++)
                s[j] = (s[j] == '+') ? '-' : '+';
            ans++;
        }
        bool flag = true;

        for (int i = 0; flag && i < n; i++)
            flag = (s[i] == '+');
        printf("Case #%d: ", test);
        if (flag)
            printf("%d\n", ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
