#include <bits/stdc++.h>
using namespace std;

int main()
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
    stack<pair<int, int>> sta;
    int ans[n];

    for (int i = 0; i < n; i++)
    {
        while (!sta.empty() and arr[i] >= sta.top().first)
        {
            sta.pop();
        }

        if (sta.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - sta.top().second;
        }

        sta.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}