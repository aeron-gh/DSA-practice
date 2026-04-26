#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7; 
int dp[101][100001];
int f(int pos, int cs, int arr[], int n, int t)
{
    if (pos == n)
    {
        return cs == t;
    }
    if(dp[pos][cs] != -1){
        return dp[pos][cs];
    }
    int a = 0;
    if (cs + arr[pos] <= t)
    {
        a = f(pos, cs + arr[pos], arr, n, t);
    }
    int b = f(pos + 1, cs, arr, n, t);
    return dp[pos][cs] = (a + b) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << f(0, 0, arr, n, t);
    return 0;
}