#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    for (int i = 0; i < k - 1; i++)
    {
        pq.push(arr[i]);
        minpq.push(arr[i]);
        cout << -1 << " " << -1 << endl;
    }

    for (int i = k - 1; i < n; i++)
    {
        pq.push(arr[i]);
        minpq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
            minpq.pop();
        }
        cout << pq.top() << " " << minpq.top() << endl;
    }

    return 0;
}