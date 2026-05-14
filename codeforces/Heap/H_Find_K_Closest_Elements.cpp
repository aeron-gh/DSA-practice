#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    int arr[n];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
    }

    for (int i = k; i < n; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
        pq.pop();
    }

    while (pq.size() != 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}