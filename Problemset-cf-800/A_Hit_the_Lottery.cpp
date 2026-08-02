#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int cnt = 0;
    while (true)
    {
        if (n == 0)
        {
            break;
        }
        if (n >= 100)
        {
            cnt++;
            n -= 100;
        }
        else if (n >= 20)
        {
            cnt++;
            n -= 20;
        }
        else if (n >= 10)
        {
            cnt++;
            n -= 10;
        }
        else if (n >= 5)
        {
            cnt++;
            n -= 5;
        }
        else if (n >= 1)
        {
            cnt++;
            n -= 1;
        }
    }
    cout << cnt;

    return 0;
}