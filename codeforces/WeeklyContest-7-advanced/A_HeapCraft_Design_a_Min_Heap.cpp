#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
    Implement only the class below.
*/

class MinHeap
{

    vector<long long> vec;

public:
    MinHeap()
    {
    }

    void insert(long long x)
    {
        vec.push_back(x);
        int i = vec.size() - 1;
        while (true)
        {
            if (i <= 0)
            {
                break;
            }
            if (vec[(i - 1) / 2] > vec[i])
            {
                swap(vec[(i - 1) / 2], vec[i]);
                i = (i - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }

    long long getMin()
    {
        if (vec.size() == 0)
        {
            return -1;
        }
        return vec[0];
    }

    long long removeMin()
    {
        if (vec.size() == 0)
        {
            return -1;
        }
        int ans = vec[0];

        int sz = vec.size();
        swap(vec[0], vec[sz - 1]);

        vec.pop_back();

        int i = 0;
        sz = vec.size();
        while (true)
        {
            if (2 * i + 1 >= sz)
            {
                break;
            }

            int a = 2 * i + 1;

            if (2 * i + 2 <= sz - 1)
            {
                if (vec[2 * i + 2] < vec[2 * i + 1])
                {
                    a = 2 * i + 2;
                }
            }

            if (vec[i] > vec[a])
            {
                swap(vec[i], vec[a]);
                i = a;
            }
            else
            {
                break;
            }
        }

        return ans;
    }

    int size()
    {
        return vec.size();
    }

    bool empty()
    {
        if (vec.size() == 0)
        {
            return true;
        }
        return false;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MinHeap heap;

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            long long x;
            cin >> x;

            heap.insert(x);
        }
        else if (type == 2)
        {
            cout << heap.getMin() << '\n';
        }
        else if (type == 3)
        {
            cout << heap.removeMin() << '\n';
        }
        else if (type == 4)
        {
            cout << heap.size() << '\n';
        }
        else
        {
            cout << heap.empty() << '\n';
        }
    }

    return 0;
}