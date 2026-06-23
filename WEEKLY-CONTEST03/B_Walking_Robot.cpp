#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, b, a;
    cin >> n >> b >> a;
    int bf = b;
    int af = a;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (a > 0)
            {
                a--;
            }
            else if (b > 0)
            {
                b--;
            }
            else
            {
                break;
            }
        }
        else
        {

            if (b > 0 && a < af)
            {
                b--;
                a++;
            }
            else if (a > 0)
            {
                a--;
            }
            else if (b > 0)
            {
                b--;
            }
            else
            {
                break;
            }
        }

        ans = i;
    }

    cout << ans + 1;

    return 0;
}