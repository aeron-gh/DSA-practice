#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int f(int i, int j, string &str)
{
    if (i == j)
    {
        return 1;
    }

    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int z = 0;
    if (str[i] == str[j])
    {
        z = 2 + f(i + 1, j - 1, str);
    }
    else
    {
        int a = f(i, j - 1, str);
        int b = f(i + 1, j, str);
        z = max(a, b);
    }
    return dp[i][j] = z;
}

string ans1;
string ans2;

void recover(int i, int j, string &str)
{
    if (i == j)
    {
        ans1 += str[i];
        return;
    }

    if (i > j)
    {
        return;
    }

    int z = 0;
    if (str[i] == str[j])
    {
        ans1 += str[i];
        ans2 += str[i];
        recover(i + 1, j - 1, str);
    }
    else
    {
        int a = f(i, j - 1, str);
        int b = f(i + 1, j, str);
        z = max(a, b);
        if (a == z)
        {
            recover(i, j - 1, str);
        }
        else
        {
            recover(i + 1, j, str);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    memset(dp, -1, sizeof dp);
    cout << f(0, str.size() - 1, str) << endl;
    recover(0, str.size() - 1, str);
    reverse(ans2.begin(), ans2.end());
    cout << ans1 + ans2;
    return 0;
}