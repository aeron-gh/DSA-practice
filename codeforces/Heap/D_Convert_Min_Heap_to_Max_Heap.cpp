#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<long long> hp;

public:
    MaxHeap()
    {
        // implement
        this->hp = hp;
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
            i = (i - 1) / 2;
        }
    }

    void removeMax()
    {
        // implement
        if (hp.size() == 0)
        {
            return;
        }
        swap(hp[0], hp[hp.size() - 1]);
        hp.pop_back();

        int i = 0;
        while (i < hp.size() - 1)
        {
            int li = (2 * i) + 1;
            int ri = (2 * i) + 2;

            int largest = i;

            if (li < hp.size() && hp[li] > hp[largest])
            {
                largest = li;
            }

            if (ri < hp.size() && hp[ri] > hp[largest])
            {
                largest = ri;
            }

            if (largest != i)
            {
                swap(hp[i], hp[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
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
    cin.tie(NULL);
    int n;
    cin >> n;
    MaxHeap m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m.insert(a);
    }
    for (int i = 0; i < n; i++)
    {
        cout << m.getMax() << " ";
        m.removeMax();
    }
    return 0;
}