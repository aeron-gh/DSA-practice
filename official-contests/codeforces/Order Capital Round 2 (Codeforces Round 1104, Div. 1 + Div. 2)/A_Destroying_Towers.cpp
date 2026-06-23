#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    arr[j] = arr[i];
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }
        cout << ans << endl;
    }

    return 0;
}