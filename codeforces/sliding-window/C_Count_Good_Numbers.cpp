#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        st.insert(a);
    }

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (st.count(arr[i]))
        {
            cnt++;
        }
    }
    cout << cnt << " ";
    for (int i = k; i < n; i++)
    {
        if (st.count(arr[i]))
        {
            cnt++;
        }
        if (st.count(arr[i - k]))
        {
            cnt--;
        }

        cout << cnt << " ";
    }
    return 0;
}