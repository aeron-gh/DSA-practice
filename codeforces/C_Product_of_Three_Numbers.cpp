#include <bits/stdc++.h>
using namespace std;

vector<int> getfactor(int no)
{
    vector<int> factors;
    for (int i = 1; i * i <= no; i++)
    {
        if (no % i == 0)
        {
            if (no == i)
            {
                factors.push_back(no / i);
            }
            else
            {
                factors.push_back(i);
                factors.push_back(no / i);
            }
        }
    }

    sort(factors.begin(), factors.end());
    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int no;
        cin >> no;
        auto factors = getfactor(no);
        int a = factors[1];
        no /= a;
        factors = getfactor(no);
        bool found = false;
        for (int f : factors)
        {
            int b = f;
            int c = no / f;
            if (a != b and b != c and a != c and b > 1 and c > 1)
            {
                found = true;
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}