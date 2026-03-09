// Contest: https://codeforces.com/contests/677363  mid-term-exam
// Problem: E
// Link: https://codeforces.com/gym/677363/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int no;
    cin >> no;
    string str = to_string(no);  
    queue<string> qu;
    qu.push("6");
    qu.push("9");

    while (true)
    {
        string c = qu.front();
        long long a = stoll(c);
        qu.pop();

        if (no < a)
        {
            break;
        } 
        cout << c << endl;
        // ans.push_back(c);
        qu.push(c + '6');
        qu.push(c + '9');
    }
    return 0;
}