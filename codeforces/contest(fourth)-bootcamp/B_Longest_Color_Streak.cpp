#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int lng = 0;
    int foo;
    cin >> foo;
    int cnt = 1;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        int no;
        cin >> no;
        if (foo == no)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            foo = no;
        }
        ans = max(cnt, ans);
    } 

    cout << ans;
    return 0;
}