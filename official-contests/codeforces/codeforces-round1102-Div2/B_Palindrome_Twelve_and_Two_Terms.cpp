#include <bits/stdc++.h>
using namespace std;

int pal(int a)
{
    if (a < 0 or (a % 10 == 0 and a != 0))
        return false;

    int original = a;
    int reversed_num = 0;

    while (a > 0)
    {
        int last_digit = a % 10;
        reversed_num = (reversed_num * 10) + last_digit;
        a /= 10; //= 10  # Integer division to remove the last digit
    }

    return original == reversed_num;
}

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
        bool a = false;
        if (n == 1)
        {
            cout << 1 << " " << 0 << endl;
        }
        else
        {
            for (int i = 12; i <= n; i = i + 12)
            {
                if (pal(n - i))
                {
                    cout << n - i << " " << i << endl;
                    a = true;
                    break;
                }
            }

            if (!a)
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}