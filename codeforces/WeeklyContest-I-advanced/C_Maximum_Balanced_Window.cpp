#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mpp;
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }

    if (mpp[1] < k)
    {
        ans = max((mpp[1] + 1), ans);
    }
    else
    {
        ans = max((mpp[1]), ans);
    }

    for (int i = k; i < n; i++)
    {

        mpp[arr[i]]++;
        mpp[arr[i - k]]--;
        if (mpp[1] < k)
        {
            ans = max((mpp[1] + 1), ans);
        }
        else
        {
            ans = max((mpp[1]), ans);
        }
    }

    cout << ans;
    return 0;
}