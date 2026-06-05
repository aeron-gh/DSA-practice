#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mpp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mpp[arr[i]]++;
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]--;
        int cur = sum - arr[i];
        if (cur % 2 == 0 && mpp[cur / 2] > 0)
        {
            ans.push_back(i + 1);
        }
        mpp[arr[i]]++;
    }

    cout << ans.size() << endl;

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}