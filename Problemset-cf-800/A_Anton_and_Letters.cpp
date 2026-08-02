#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    getline(cin, str);
    set<char>st;
    for (auto a : str)
    {
        // cout << a;
        if (a >= 'a' and a <= 'z')
        {
            st.insert(a);
        }
    }
    cout << st.size();
    return 0;
}