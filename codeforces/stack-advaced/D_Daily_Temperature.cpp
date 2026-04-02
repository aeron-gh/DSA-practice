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

    for (int i = n-1; i >= 0; i--)
    {
        while (!sta.empty() and arr[i] >= arr[sta.top()])
        {
            sta.pop();
        }

        if (sta.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(sta.top() -  i);
        }

        sta.push(i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}