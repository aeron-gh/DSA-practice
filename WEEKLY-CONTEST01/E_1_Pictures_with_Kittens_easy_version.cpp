#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long

signed main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;

    if (k == 1 && x < n)
    {
        cout << -1;
        return 0;
    }

    vector<bool> taken(n, false);

    for (int i = 0; i <= n - k; i++)
    {
        int maxx = 0;
        int maxxindex = 0;
        for (int j = i; j < i + k; j++)
        {
            if (x <= 0)
            {
                if (taken[j] == true)
                {
                    maxxindex = i;
                    continue;
                }
            }
            else if (arr[j] > maxx)
            {
                maxx = arr[j];
                maxxindex = j;
            }
        }

        x--;

        if (x >= 0)
        {
            cnt += maxx;
            taken[maxxindex] = true;
        }
        else
        {
            if (taken[maxxindex] == false)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;
}