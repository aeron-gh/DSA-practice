#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    int arr[7];
    while (q--)
    {
        int mno = INT_MIN;
        int idex = 0;
        for (int i = 0; i < 7; i++)
        {
            int no;
            cin >> arr[i];
            if (arr[i] > mno)
            {
                mno = arr[i];
                idex = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 7; i++)
        {
            if (idex == i)
            {
                ans += arr[i];
            }
            else
            {
                ans -= arr[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}