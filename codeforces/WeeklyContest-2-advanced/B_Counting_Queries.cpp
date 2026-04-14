#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            cout << mpp[x] << endl;
        }
        else if (t == 2)
        {
            int l = 0;
            int r = n - 1;
            int a = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (arr[mid] < x)
                {
                    a = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << a + 1 << endl;
        }
        else
        {
            int l = 0;
            int r = n - 1;
            int a = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (arr[mid] > x)
                {
                    a = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (a == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << (n - a) << endl;
            }
        }
    }

    return 0;
}