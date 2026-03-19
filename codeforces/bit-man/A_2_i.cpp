#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int no;
    cin >> no;
    // int pw = 1;
    // while (pw <= no)
    // {
    //     pw *= 2; 
    // pw = pw / 2;
    // vector<int> ans;
    // while (pw > 0)
    // {
    //     ans.push_back(pw);
    //     pw /= 2;
    // }

    // for (int i = ans.size() - 1; i >= 0; i--)
    // {
    //     cout << ans[i] << " ";
    // }

    int i = 0;
    // while (no >= pow(2, i))
    // {
    //     cout << pow(2, i) << " ";
    //     i++;
    // }

    while (no >= (1LL << i))
    {
        cout << (1LL << i) << " ";
        i++;
    }

    // int x = 1;
    // while (x < no)
    // {
    //     cout << x << " ";
    //     x *= 2;
    // }
    return 0;
}