#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    long long val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(long long x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

/*
    Implement only this function.
*/

int countBetterEmployees(TreeNode *root)
{   
    if (root->left == nullptr and root->right == nullptr)
    {
         
    }

    countBetterEmployees(root->left);
    root->val;
    countBetterEmployees(root->right);
}

TreeNode *build(
    map<long long, TreeNode *> &mp,
    long long val,
    vector<vector<long long>> &inp,
    map<long long, int> &pos)
{
    if (val == -1)
        return nullptr;

    if (!mp.count(val))
        mp[val] = new TreeNode(val);

    auto node = mp[val];

    int idx = pos[val];

    node->left = build(
        mp,
        inp[idx][1],
        inp,
        pos);

    node->right = build(
        mp,
        inp[idx][2],
        inp,
        pos);

    return node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<long long>> inp(
        N,
        vector<long long>(3));

    map<long long, int> pos;

    for (int i = 0; i < N; i++)
    {
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];

        pos[inp[i][0]] = i;
    }

    map<long long, TreeNode *> mp;

    auto root = build(
        mp,
        inp[0][0],
        inp,
        pos);

    cout
        << countBetterEmployees(root)
        << '\n';
}