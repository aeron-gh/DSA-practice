#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int f(int i, int j, string &s, string &t)
{
    if (i == s.size())
    {
        return t.size() - j;
    }

    if (j == t.size())
    {
        return s.size() - i;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int z = 0;
    if (s[i] == t[j])
    {
        z = f(i + 1, j + 1, s, t);
    }
    else
    {
        int a = 1 + f(i, j + 1, s, t);
        int b = 1 + f(i + 1, j, s, t);
        int c = 1 + f(i + 1, j + 1, s, t);
        z = min({a, b, c});
    }
    return dp[i][j] = z;
}

// int add = 0;
// int remove = 0;

int foo = 0;
// i - remove + add

void recover(int i, int j, string &s, string &t)
{
    if (i == s.size())
    {
        if(j == t.size()) return;
        cout << "INSERT " << i + foo << " " << t[j] << endl;
        foo++;
        recover(i, j + 1, s, t);
        return;
    }

    if (j == t.size())
    {
        cout << "DELETE " << i + foo << " " << endl;
        foo--;
        recover(i + 1, j, s, t);
        return;
    }

    if (s[i] == t[j])
    {
        recover(i + 1, j + 1, s, t);
    }
    else
    {
        int a = 1 + f(i, j + 1, s, t);     // insert
        int b = 1 + f(i + 1, j, s, t);     // delete
        int c = 1 + f(i + 1, j + 1, s, t); // replace
        int z = min({a, b, c});
        if (z == a)
        {
            cout << "INSERT " << foo + i << " " << t[j] << endl;
            foo++;
            recover(i, j + 1, s, t);
        }
        else if (z == b)
        {
            cout << "DELETE " << i + foo << endl;
            foo--;
            recover(i + 1, j, s, t);
        }
        else
        {
            cout << "REPLACE " << i + foo << " " << t[j] << endl;
            recover(i + 1, j + 1, s, t);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, s, t) << endl;
    recover(0, 0, s, t);
    return 0;
}