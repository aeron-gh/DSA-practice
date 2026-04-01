// MAH

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> nextSmallestRight(int arr[], int n)
{
    vector<int> ans;
    stack<int> sta;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sta.empty() and arr[i] <= arr[sta.top()])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans.push_back(n + 1);
        }
        else
        {
            ans.push_back(sta.top() + 1);
        }
        sta.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nextSmallestLeft(int arr[], int n)
{
    vector<int> ans;
    stack<int> sta;
    for (int i = 0; i < n; i++)
    {
        while (!sta.empty() and arr[i] <= arr[sta.top()])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(sta.top() + 1);
        }
        sta.push(i);
    }
    return ans;
}

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

    vector<int> smallestRight = nextSmallestRight(arr, n);
    vector<int> smallestLeft = nextSmallestLeft(arr, n);
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(((smallestRight[i] - smallestLeft[i] - 1) * arr[i]), ans);
    }
    cout << ans;
    return 0;
}


