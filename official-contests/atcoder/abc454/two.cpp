#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<int> st;
    bool rep = false;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (st.count(a))
        {
            rep = true;
        }
        st.insert(a);
    }
    if (rep)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    rep = false;

    for (int i = 1; i <= m; i++)
    {
        if (!st.count(i))
        {
            rep = true;
        }
    }

    if (rep)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}