// Contest: https://codeforces.com/contests/677363  mid-term-exam
// Problem: A
// Link: https://codeforces.com/gym/677363/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

int lstdigit(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + lstdigit(n / 10);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = n;
    // stack<int> st;
    while (true)
    {
        if (ans >= 0 && ans <= 9)
        {
            cout << ans;
            return 0;
        }
        else
        {
            ans = lstdigit(ans);
        }
        // st.push(ans);
    }

    return 0;
}