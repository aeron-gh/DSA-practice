#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> st;

    while (n--)
    {
        int no;
        cin >> no;
        st.insert(no);
        cout << st.size() << " ";
    }

    return 0;
}