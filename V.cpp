#include <bits/stdc++.h>
using namespace std;

enum type
{
    BUY,
    SELL
};

int f(int pos, int arr[], int n, int k, int take)
{
    if (pos >= n or k == 0)
    {
        return 0;
    }

    int z = 0;
    if (take == BUY)
    {
        int a = -arr[pos] + f(pos + 1, arr, n, k - 1, SELL);
        int b = f(pos + 1, arr, n, k, BUY);
        z = max(a, b);
    }
    else
    {
        int a = arr[pos] + f(pos + 2, arr, n, k - 1, BUY);
        int b = f(pos + 1, arr, n, k, SELL);
        z = max(a, b);
    }
    return z;
}
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
    cout << f(0, arr, n, k * 2, BUY);

    return 0;
}