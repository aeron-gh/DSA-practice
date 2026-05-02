#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, int k, string str1, string str2, string str3)
{
    if (i == str1.size() or j == str2.size() or k == str3.size())
    {
        return 0;
    }

    int z = 0;
    if (str1[i] == str2[j] and str1[i] == str3[k])
    {
        int a = f(i + 1, j + 1, k + 1, str1, str2, str3);
        z = a;
    }
    else 
    {
        int a = f(i + 1, j, k, str1, str2, str3);
        int b = f(i, j + 1, k, str1, str2, str3);
        int c = f(i, j, k + 1, str1, str2, str3);
        z = max({a, b, c});
    }

    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << f(0, 0, 0, s1, s2, s3);
    return 0;
}