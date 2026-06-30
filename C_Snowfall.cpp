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

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 6 == 0)
            {  
                ans.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 6 != 0)
            {
                ans.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}