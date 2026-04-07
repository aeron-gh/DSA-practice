#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string target;
    cin >> target;
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}