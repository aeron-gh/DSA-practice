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

    int nos = 0;

    for (int i = 0; i < n; i++)
    {
        nos = nos ^ arr[i];
    }
    int ith = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & nos)
        {
            ith = i;
            break;
        }
    }
    vector<int> grp1;
    vector<int> grp2;
    int ans[2] = {0, 0};

    for (int a : arr)
    {
        if ((1 << ith) & a)
        {
            grp1.push_back(a);
        }
        else
        {
            grp2.push_back(a);
        }
    }

    for (int no : grp1)
    {
        ans[0] = ans[0] ^ no;
    }
    for (int no : grp2)
    {
        ans[1] = ans[1] ^ no;
    }
    sort(ans, ans + 2);
    cout << ans[0] << " " << ans[1];

    return 0;
}