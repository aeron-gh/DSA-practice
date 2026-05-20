#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/

class StatisticsEngine {
public:

    StatisticsEngine() {

    }

    void insert(long long x) {

    }

    long long getMean() {

        return -1;
    }

    long long getMedian() {

        return -1;
    }

    long long getMode() {

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    StatisticsEngine se;

    while(Q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            long long x;
            cin >> x;

            se.insert(x);
        }
        else if(type == 2)
        {
            cout << se.getMean() << '\n';
        }
        else if(type == 3)
        {
            cout << se.getMedian() << '\n';
        }
        else
        {
            cout << se.getMode() << '\n';
        }
    }

    return 0;
}