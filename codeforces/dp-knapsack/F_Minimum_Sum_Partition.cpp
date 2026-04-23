#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[201][20001];

bool f(int pos, int target, int cs, int arr[], int n)
{
    if (pos == n)
    {
        return target == cs;
    }

    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }

    bool a = false;
    if (cs + arr[pos] <= target)
    {
        a = f(pos + 1, target, cs + arr[pos], arr, n);
    }
    bool b = f(pos + 1, target, cs, arr, n);
    return dp[pos][cs] = a or b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    int a = 0;
    if (s % 2 == 0)
    {
        a = s / 2;
    }
    else
    {
        a = (s / 2) + 1;
    }

    for (int i = a; i <= s; i++)
    {
        memset(dp, -1, sizeof dp);
        if (f(0, i, 0, arr, n))
        {
            int a = abs(i - s);
            cout << abs(a - i);
            return 0;
        }
    }

    return 0;
}