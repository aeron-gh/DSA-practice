#include <bits/stdc++.h>
using namespace std;

void f(int curPos, int n, vector<int> &path, vector<vector<int>> &ans)
{
    if (curPos > n)
    {
        return;
    }

    if (curPos == n)
    {
        ans.push_back(path);
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        path.push_back(i);
        f(curPos + i, n, path, ans);
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    vector<vector<int>> ans;
    f(0, n, vec, ans);

    for (auto x : ans)
    {
        for (auto a : x)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}