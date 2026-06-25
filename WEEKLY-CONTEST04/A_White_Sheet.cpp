// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    int x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    if (y2 > y6 and x2 > x4)
    {
        cout << "Yes" << endl;
    }
    else if (y3 > y1 and x5 > x1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}