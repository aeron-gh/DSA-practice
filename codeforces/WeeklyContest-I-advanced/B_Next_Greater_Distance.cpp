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
    stack<int> sta;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sta.empty() && arr[sta.top()] <= arr[i])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = sta.top() - i;
        }
        sta.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}