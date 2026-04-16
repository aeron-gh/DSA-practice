#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mpp;
    set<pair<int, int>> st;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto x : mpp)
    {
        st.insert({x.second, -x.first});
    }

    ans.push_back(st.rbegin()->second);

    for (int i = k; i < n; i++)
    {
        st.erase({mpp[arr[i]], -arr[i]});
        mpp[arr[i]]++;
        st.insert({mpp[arr[i]], -arr[i]});

        st.erase({mpp[arr[i - k]], -arr[i - k]});
        mpp[arr[i - k]]--;
        st.insert({mpp[arr[i - k]], -arr[i - k]});

        ans.push_back(st.rbegin()->second);
    }

    for (int i : ans)
    {
        cout << -i << " ";
    }

    return 0;
}