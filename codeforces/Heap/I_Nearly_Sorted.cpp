#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }

    vector<int> ans;

    for (int i = k + 1; i < n; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}