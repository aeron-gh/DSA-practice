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
    int pre[n];
    int foo = 0;
    
    for (int i = 0; i < n; i++)
    {
        foo += arr[i];
        pre[i] = foo;
    }

    foo = 0;
    reverse(arr, arr + n);
    int rpre[n];

    for (int i = 0; i < n; i++)
    {
        foo += arr[i];
        rpre[i] = foo;
    }
    reverse(rpre, rpre + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] == rpre[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

/*

1 4 9 11 13

2 2 5 3 1

2 4 9 12 13

*/