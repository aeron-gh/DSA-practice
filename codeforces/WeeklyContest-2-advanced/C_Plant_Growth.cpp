#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> sta;
    vector<int> ans(n), grand(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sta.empty() && arr[sta.top()] <= arr[i])
        {
            sta.pop();
        }
        // if (sta.size() >= 2)
        // {
        //     ans++;
        // }
        if (sta.empty())
        {
            ans[i] = -1;
            grand[i] = -1;
        }
        else
        {
            ans[i] = sta.top();
            grand[i] = ans[ans[i]];
        }
        sta.push(i);
    }

    int cnt = 0;
    for (auto i : grand)
    {
        if (i != -1)
            cnt++;
    }

    cout << cnt;

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     stack<int> sta;
//     vector<int> ans(n);
//     vector<int> ans2(n);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!sta.empty() && sta.top() <= arr[i])
//         {
//             sta.pop();
//         }
//         if (sta.empty())
//         {
//             ans[i] = 0;
//         }
//         else
//         {
//             ans[i] = sta.top();
//         }

//         sta.push(arr[i]);
//     }

//     stack<int> sta2;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!sta2.empty() && sta2.top() <= ans[i])
//         {
//             sta2.pop();
//         }
//         if (sta2.empty())
//         {
//             ans2[i] = 0;
//         }
//         else
//         {
//             ans2[i] = sta2.top();
//         }
//         sta2.push(ans[i]);
//     }

//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (ans2[i] != 0)
//         {
//             cnt++;
//         }
//     }
//     cout << cnt;
//     return 0;
// }