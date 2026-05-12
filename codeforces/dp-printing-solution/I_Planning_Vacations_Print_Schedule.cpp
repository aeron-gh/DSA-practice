#include <bits/stdc++.h>
using namespace std;

int f(int i, int prev, vector<int> &arr)
{
    int n = arr.size();
    if (i == n)
    {
        return 0;
    }

    int b = 1 + f(i + 1, 0, arr);
    int z = b;
    if (arr[i] == 1 and prev != 1)
    {
        int a = f(i + 1, 1, arr);
        z = min(a, b);
    }

    if (arr[i] == 2 and prev != 2)
    {
        int a = f(i + 1, 2, arr);
        z = min(a, b);
    }

    if (arr[i] == 3)
    {
        if (prev != 1)
        {
            int a = f(i + 1, 1, arr);
            z = min({a, b});
        }
        if (prev != 2)
        {
            int a = f(i + 1, 2, arr);
            z = min({a, b, z});
        }
    }

    return z;
}

string str;

void recover(int i, int prev, vector<int> &arr)
{
    int n = arr.size();
    if (i == n)
    {
        return;
    }

    int b = 1 + f(i + 1, 0, arr);

    if (arr[i] == 1 and prev != 1)
    {
        int a = f(i + 1, 1, arr);

        if (a < b)
        {
            str += 'C';
            recover(i + 1, 1, arr);
        }
        else
        {
            str += 'R';
        }
    }

    if (arr[i] == 2 and prev != 2)
    {
        int a = f(i + 1, 2, arr);
        if (a < b)
        {
            str += 'G';
            recover(i + 1, 2, arr);
        }
        else
        {
            str += 'R';
        }
    }

    if (arr[i] == 3)
    {
        if (prev != 1)
        {
            int a = f(i + 1, 1, arr);
            if (a < b)
            {
                str += 'C';
                recover(i + 1, 1, arr);
            }
            else
            {
                str += 'R';
            }
        }

        if (prev != 2)
        {
            int a = f(i + 1, 2, arr);
        }
    }

    if (arr[i] == 0)
    {
        str += 'R';
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << f(0, 0, arr);

    return 0;
}