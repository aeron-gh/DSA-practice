#include <bits/stdc++.h>
using namespace std;

int dp[31][31][31][31][31];
int f(int i, int j, int k, int l, int m, string &str1, string &str2, string &str3, string &str4, string &str5)
{
    if (i == str1.size() or j == str2.size() or k == str3.size() or l == str4.size() or m == str5.size())
    {
        return 0;
    }
    if (dp[i][j][k][l][m] != -1)
    {
        return dp[i][j][k][l][m];
    }

    int z = 0;
    if (str1[i] == str2[j] and str1[i] == str3[k] and str1[i] == str4[l] and str1[i] == str5[m])
    {
        int a = 1 + f(i + 1, j + 1, k + 1, l + 1, m + 1, str1, str2, str3, str4, str5);
        z = a;
    }
    else
    {
        int a = f(i + 1, j, k, l, m, str1, str2, str3, str4, str5);
        int b = f(i, j + 1, k, l, m, str1, str2, str3, str4, str5);
        int c = f(i, j, k + 1, l, m, str1, str2, str3, str4, str5);
        int d = f(i, j, k, l + 1, m, str1, str2, str3, str4, str5);
        int e = f(i, j, k, l, m + 1, str1, str2, str3, str4, str5);
        z = max({a, b, c, d, e});
    }

    return dp[i][j][k][l][m] = z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0, 0, 0, s1, s2, s3, s4, s5);
    return 0;
}