//https://atcoder.jp/contests/abc212/tasks/abc212_c


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    set<int> st;

    for (int i = 0; i < n; i++)
    {

        int a;
        cin >> a;
        st.insert(a);
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int no;
        cin >> no;
        auto it = st.lower_bound(no);
        if (it != st.end())
        {
            ans = min(abs(*it - no), ans);
        }
        if (it != st.begin())
        {
            it--;
            ans = min(abs(*it - no), ans);
        }
    }

    cout << ans;

    return 0;
}