#include <bits/stdc++.h>
using namespace std;

// sq root decomposition

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    int arr[n];
    int blocksize = sqrt(n) + 1;
    int B[blocksize];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int a = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        a += arr[i];
        if ((i + 1) % blocksize == 0 || i == n - 1)
        {
            B[j] += a;
            a = 0;
            j++;
        }
    }

    for (int i = 0; i < blocksize; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
        {
            u--;
            int change = v - arr[u];
            arr[u] = v;
            B[u / blocksize] += change;
        }
        else
        {
            u--;
            v--;
            int ans = 0;
            while (u <= v)
            {
                if (u % blocksize == 0 and u + blocksize - 1 <= v)
                {
                    ans += B[u / blocksize];
                    u += blocksize;
                }
                else
                {
                    ans += arr[u];
                    u++;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}