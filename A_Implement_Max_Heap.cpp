#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/
class MaxHeap
{
    vector<int> hp;

public:
    MaxHeap()
    {
        // implement
    }

    void insert(long long x)
    {
        hp.push_back(x);
        int i = hp.size() - 1;
        while (i > 0)
        {
            if (hp[(i - 1) / 2] < x)
            {
                swap(hp[i], hp[(i - 1) / 2]);
            }
            else
            {
                break;
            }
        }
    }

    void removeMax()
    {
        // implement
    }

    long long getMax()
    {
        // implement
        if (hp.size() == 0)
        {
            return -1;
        }
        return hp[0];
    }

    long long size()
    {
        // implement
        return hp.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MaxHeap hp;

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            long long x;
            cin >> x;
            hp.insert(x);
        }
        else if (type == 2)
        {
            hp.removeMax();
        }
        else if (type == 3)
        {
            cout << hp.getMax() << "\n";
        }
        else
        {
            cout << hp.size() << "\n";
        }
    }

    return 0;
}