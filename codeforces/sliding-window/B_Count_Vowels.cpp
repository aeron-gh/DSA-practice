#include <bits/stdc++.h>
using namespace std;
#define int long long

bool present(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        return true;
    }
    if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
    {
        return true;
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;
    int a = 0;
    for (int i = 0; i < k; i++)
    {
        if (present(arr[i]))
        {
            a++;
        }
    }
    cout << a << " ";

    for (int i = k; i < n; i++)
    {
        if (present(arr[i]))
        {
            a++;
        }
        if (present(arr[i - k]))
        {
            a--;
        }
        cout << a << " ";
    }
    return 0;
}