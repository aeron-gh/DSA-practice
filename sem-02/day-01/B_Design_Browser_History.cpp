#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/

class BrowserHistory
{
    stack<string> st1;
    stack<string> st2;

public:
    BrowserHistory(string homepage)
    {
        st1.push(homepage);
    }

    void visit(string url)
    {
        st1.push(url);
        while (!st2.empty())
        {
            st2.pop();
        }
    }

    string back(int steps)
    {
        if (steps >= st1.size())
        {
            steps = st1.size() - 1;
        }
        while (steps)
        {
            st2.push(st1.top());
            st1.pop();
            steps--;
        }

        return st1.top();
    }

    string forward(int steps)
    {
        if (steps >= st2.size())
        {
            steps = st2.size();
        }

        while (steps)
        {
            st1.push(st2.top());
            st2.pop();
            steps--;
        }

        return st1.top();
    }

    string current()
    {
        return st1.top();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string homepage;

    cin >> homepage;

    BrowserHistory bh(homepage);

    int Q;

    cin >> Q;

    while (Q--)
    {
        int type;

        cin >> type;

        if (type == 1)
        {
            string url;

            cin >> url;

            bh.visit(url);
        }
        else if (type == 2)
        {
            int steps;

            cin >> steps;

            cout
                << bh.back(steps)
                << '\n';
        }
        else if (type == 3)
        {
            int steps;

            cin >> steps;

            cout
                << bh.forward(steps)
                << '\n';
        }
        else
        {
            cout
                << bh.current()
                << '\n';
        }
    }

    return 0;
}