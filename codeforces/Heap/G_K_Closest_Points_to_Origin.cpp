#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n][2];
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 0; i < k; i++)
    {
        pq.push({(arr[i][0] * arr[i][0]) + (arr[i][1] * arr[i][1]), i});
    }
    for (int i = k; i < n; i++)
    {
        pq.push({(arr[i][0] * arr[i][0]) + (arr[i][1] * arr[i][1]), i});
        pq.pop();
    }
    while (!pq.empty())
    {
        cout << arr[pq.top().second][0] << " " << arr[pq.top().second][1] << endl;
        pq.pop();
    }
    return 0;
}