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
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!sta.empty() && sta.top() <= arr[i])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(sta.top());
        }
        sta.push(arr[i]);
    }


    for (int i = 0; i < n; i++)
    {
        if (ans[i] == -1)
        {
            cout << "X ";
        }
        else
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}