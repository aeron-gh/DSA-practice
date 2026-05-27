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

    stack<int> st;
    int ans = 0;
    vector<int> vec;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() <= arr[i])
        {
            st.pop();
        }
        st.push(arr[i]);
        ans = max(ans, (int)st.size());
        vec.push_back(st.size());
        // cout << ans << " ";
    }

    cout << ans << " ";
    int a = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == ans)
        {
            a++;
        }
    }
    cout << a;
    return 0;
}