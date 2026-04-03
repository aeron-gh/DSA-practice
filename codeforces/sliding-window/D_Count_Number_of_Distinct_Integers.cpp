#include <bits/stdc++.h>
using namespace std;

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
    map<int, int> mpp;
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }
    cout << mpp.size() << " ";

    for (int i = k; i < n; i++)
    {

        mpp[arr[i]]++;
        if (mpp.count(arr[i - k]))
        {
            mpp[arr[i - k]]--;
            if (mpp[arr[i - k]] == 0)
            {
                mpp.erase(arr[i - k]);
            }
        }
        cout << mpp.size() << " ";
    }
    return 0;
}