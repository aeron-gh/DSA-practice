#include <bits/stdc++.h>
using namespace std;

bool isv(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string, vector<string>> mpp;
    while (n--)
    {
        string str;
        cin >> str;
        string key;
        for (int i = 0; i < str.size(); i++)
        {
            if (isv(str[i]))
            {
                key += 'v';
            }
            else
            {
                key += 'c';
            }
        }
        mpp[key].push_back(str);
    }
    for (auto m : mpp)
    {
        sort(m.second.begin(), m.second.end());
        for (auto a : m.second)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}