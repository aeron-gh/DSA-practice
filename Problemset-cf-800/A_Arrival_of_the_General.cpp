#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    int min = INT_MAX;
    int max = INT_MIN;
    int a = -1;
    int b = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (min >= arr[i])
        {
            a = i;
            min = arr[i];
        }
        if (max < arr[i])
        {
            b = i;
            max = arr[i];
        }
    }

    int ans = 0;
    if (a > b)
    {
        ans += b;
        ans += ((n - 1) - a);
    }
    if (a < b)
    {
        ans += b;
        ans += ((n - 1) - a) - 1;
    }
   
    cout << ans;
    return 0;
}