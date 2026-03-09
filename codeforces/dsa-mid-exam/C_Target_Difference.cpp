#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

bool existsPairWithDifference(Node *head, long long X)
{
    // TODO: implement this

    auto ptr = head;
    set<int> st;
    while (ptr != nullptr)
    {
        int n = ptr->val;
        if (st.count(X + n) || st.count( n - X ))
        {
            return true;
        }
        st.insert(n);
        ptr = ptr->next;
    }

    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X;
    cin >> N >> X;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Node *head = new Node(arr[0]);
    Node *cur = head;

    for (int i = 1; i < N; i++)
    {
        cur->next = new Node(arr[i]);
        cur = cur->next;
    }

    if (existsPairWithDifference(head, X))
        cout << "YES\n";
    else
        cout << "NO\n";
}