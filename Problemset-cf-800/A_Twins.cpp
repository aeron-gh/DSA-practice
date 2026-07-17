#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    int sum = 0;
    for (auto &a : vec)
    {
        cin >> a;
        sum += a;
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int cnt = 0;
    int foo = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < foo)
        {
            break;
        }
        cnt++;
        foo += vec[i];
        sum -= vec[i];
    }
    cout << cnt;
    return 0;
}