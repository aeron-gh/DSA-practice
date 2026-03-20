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
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int sum = 0;
        for (int a : arr)
        {
            if (a & (1 << i))
            {
                sum += 1;
            }
        }

        if (sum % 3 != 0)
        {
            ans = (1 << i) | ans;
        }
        else
        {
            ans = ~(1 << i) & ans;
        }
    }

    cout << ans;
    return 0;
}