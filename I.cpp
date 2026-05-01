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
    // sum pre reverse arr
    int preArr[n];
    int a = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        a = max(arr[i], a);
        preArr[i] = a;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, preArr[i] - arr[i]);
    }
    cout << ans;

    return 0;
}