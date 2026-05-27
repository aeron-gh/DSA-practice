#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    long long val;

    ListNode *next;

    ListNode(long long x)
    {
        val = x;

        next = nullptr;
    }
};

/*
    Implement only this function.
*/

long long countPairs(
    ListNode *head,
    long long x)
{
    auto ptr = head;
    map<int, int> mpp;
    long long ans = 0;

    while (ptr != nullptr)
    {
        int target = x - ptr->val;
        if (mpp.count(target))
        {
            ans += mpp[target];
        }
        mpp[ptr->val]++;
        ptr = ptr->next;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int N;

    cin >> N;

    ListNode *head = nullptr;

    ListNode *tail = nullptr;

    for (int i = 0; i < N; i++)
    {
        long long x;

        cin >> x;

        auto node =
            new ListNode(x);

        if (!head)
        {
            head = node;

            tail = node;
        }
        else
        {
            tail->next = node;

            tail = node;
        }
    }

    long long X;

    cin >> X;

    cout
        << countPairs(
               head,
               X)
        << '\n';

    return 0;
}