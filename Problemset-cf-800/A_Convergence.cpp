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
        sort(arr, arr + n);
        int a = n / 2;
        int cnt = 0, cnt1 = 0;
        for (int i = 0; i < a; i++)
        {
            if (arr[i] != arr[a])
            {
                cnt++;
            }
        }
        
        for (int i = a + 1; i < n; i++)
        {
            if (arr[i] != arr[a])
            {
                cnt1++;
            }
        }
        cout << max(cnt, cnt1) << endl;
    }

    return 0;
}