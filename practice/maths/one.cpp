#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 778900;
    string str;
    while (n != 0)
    {
        cout << n % 10;
        n /= 10;
    }
   
    return 0;
}