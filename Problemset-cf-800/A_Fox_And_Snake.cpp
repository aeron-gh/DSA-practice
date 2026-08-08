#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int foo = 1;
    for (int i = 0; i < n; i++)
    {   bool a = false;
        for (int j = 0; j < m; j++)
        {
            if (i % 2 == 0)
            {
                cout << '#';
            }
            else if (i % 2 != 0)
            {
                if (foo % 2 == 0)
                {
                    if (j == 0)
                    {
                        cout << '#';
                    }
                    else
                    {
                        cout << '.';
                    }
                }
                else if (foo % 2 != 0)
                {
                    if (j == m - 1)
                    {
                        cout << '#';
                    }
                    else
                    {
                        cout << '.';
                    }
                }
                a = true;
                
            }
        }
        if(a == true){
            foo++;
        }
        cout << endl;
    }

    return 0;
}