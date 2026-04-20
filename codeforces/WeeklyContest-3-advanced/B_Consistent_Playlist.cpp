#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void build(int n)
    {
        Node *tail = nullptr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            Node *node = new Node(x);

            if (!head)
                head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }

    ~LinkedList() {}
};

/*
    Implement only this function
*/
int countConsistentSegments(Node *head, int k)
{
    auto ptr = head;
    int cnt = 0;
    vector<int> vec;
    while (ptr != nullptr)
    {
        vec.push_back(ptr->val);
        ptr = ptr->next;
    }
    // for (int i = 1; i < k - 1; i++)
    // {
    //     if (vec[i] == vec[i - 1])
    //     {   
    //         cnt++;
    //     }
    // }

    for (int i = k - 1; i < vec.size(); i++)
    {
        if (vec[i - (k -1)] == vec[i])
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    int k;
    cin >> k;

    cout << countConsistentSegments(ll.head, k) << '\n';

    return 0;
}