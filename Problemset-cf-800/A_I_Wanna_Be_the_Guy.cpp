#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    int a;
    cin >> a;
    set<int> st;
    while (a--)
    {
        int foo;
        cin >> foo;
        st.insert(foo);
    }

    cin >> a;
    while (a--)
    {
        int foo;
        cin >> foo;
        st.insert(foo);
    }
    
    if (st.size() == n)
    {
        cout << "I become the guy.";
    }
    else
    {
        cout << "Oh, my keyboard!";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}
