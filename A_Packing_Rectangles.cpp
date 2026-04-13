#include <bits/stdc++.h>
using namespace std;

bool check(int mA, int a)
{
    if(mA >= a){
        return true;
    }else{
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h, n;
    cin >> w >> h >> n;
    int l = h;
    int r = h * n;
    int a = w * n * h;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid * mid, a))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}