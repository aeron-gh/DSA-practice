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

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (arr[a - 1] != i + 1)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}