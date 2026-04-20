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

    ~LinkedList()
    {
        // Do not delete nodes (safe for potential cycles in other problems)
    }
};

/*
    Implement only the function below.
*/

int countBetterSongs(Node *head)
{
    int a = head->val;
    auto ptr = head->next;
    int cnt = 0;
    while (ptr != NULL and ptr->next != NULL)
    {
        int b = ptr->val;       // a
        int c = ptr->next->val; // b
        if (a < b and b > c)
        {
            cnt++;
        }
        a = b;
        ptr = ptr->next;
    }
    return cnt;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    cout << countBetterSongs(ll.head) << '\n';

    return 0;
}