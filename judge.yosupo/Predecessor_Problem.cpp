// https://judge.yosupo.jp/problem/predecessor_problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> st;
    int n, q;
    string str;
    cin >> n >> q;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            st.insert(i);
        }
    }

    while (q--)
    {
        int T, k;
        cin >> T >> k;
        if (T == 0)
        {
            st.insert(k);
        }
        else if (T == 1)
        {
            st.erase(k);
        }
        else if (T == 2)
        {
            if (st.count(k))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (T == 3)
        {
            auto it = st.lower_bound(k);
           
            if (it != st.end())
            {
                cout << *it << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (T == 4)
        {
            auto it = st.upper_bound(k);

            if (it != st.begin())
            {
                it--;
                cout << *it << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}