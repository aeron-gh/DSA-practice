// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> cnt(200001);

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         cnt[x]++;
//     }

//     int lo = 1, hi = n, b = 0;

//     while (lo <= hi)
//     {
//         int mid = (lo + hi) / 2;

//         int h = 0;

//         for (int i = 1; i <= 200000; i++)
//         {
//             h += cnt[i] / mid;
//         }

//         if (h >= k)
//         {
//             b = mid;
//             lo = mid + 1;
//         }
//         else
//         {
//             hi = mid - 1;
//         }
//     }

//     vector<int> ans;

//     for (int i = 1; i <= 200000 && ans.size() < k; i++)
//     {
//         for (int j = 0; j < cnt[i] / b && ans.size() < k; j++)
//         {
//             ans.push_back(i);
//         }
//     }

//     for (int x : ans)
//     {
//         cout << x << ' ';
//     }
// }



