#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    while (n--)
    {
        int no;
        cin >> no;

        if (st.empty())
        {
            st.push(no);
        }
        else if (abs(st.top() - no) == 1)
        {
            st.pop();
        }
        else
        {
            st.push(no);
        }
    }
    
    vector<int> ans;
    if (st.empty())
    {
        cout << "EMPTY";
        return 0;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}