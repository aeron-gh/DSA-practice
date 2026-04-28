#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;

int f(int pos, int arr[], int n, bool move)
{
    if (pos == n)
    {
        return 1;
    }
    if (pos > n)
    {
        return 0;
    }
    int c = 0;
    int a = f(pos + 1, arr, n, false);
    int b = f(pos + 2, arr, n, false);
    if (move == false)
    {
        c = f(pos + 3, arr, n, true);
    }
    return (a + b + c) % md;
}

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
    cout << f(0, arr, n, false);
    return 0;
}