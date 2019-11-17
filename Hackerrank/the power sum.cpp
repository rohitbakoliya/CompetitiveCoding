//https://www.hackerrank.com/challenges/the-power-sum/problem

#include <bits/stdc++.h>

using namespace std;

int solve(int x , int n , int num)
{
    if(pow(num , n) < x)
    {
        return solve(x , n , num +1 ) + solve(x - pow(num ,n ) , n , num + 1);
    }

    else if(pow(num , n )==x) return 1;
    else return 0;
}
// Complete the powerSum function below.
int powerSum(int X, int N) {

    return solve(X , N , 1);


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
