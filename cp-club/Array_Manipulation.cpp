#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    vector<int> vec(n + 2);
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a] += c;
        vec[b + 1] -= c;
    }

    int a = 0;
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        a += vec[i];
        if (ans < a)
        {
            ans = a;
        }
    }

    cout << ans;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, k;
//     cin >> n >> k;
//     vector<int> vec(n);
//     while (k--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--;
//         b--;
//         vec[a] += c;
//         if (b + 1 < n)
//         {
//             vec[b + 1] -= c;
//         }
//     }

//     int a = 0;
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         a += vec[i];
//         if (ans < a)
//         {
//             ans = a;
//         }
//     }
//     cout << ans;
//     return 0;
// }
