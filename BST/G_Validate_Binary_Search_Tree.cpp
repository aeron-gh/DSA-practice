#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)nodes.size())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (nodes[i] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

/*
    Implement only the function below.
    Return whether the binary tree is a valid Binary Search Tree.
*/
bool isValidBST(TreeNode *root)
{

    if (root == nullptr)
        return true;

    if (root->left != nullptr && root->left->val >= root->val)
        return false;

    if (root->right != nullptr && root->right->val <= root->val)
        return false;
    // if (root->left == nullptr or root->right == nullptr or root->left->val < root->right->val)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    bool a = isValidBST(root->left);
    bool b = isValidBST(root->right);

    if (a and b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++)
        cin >> nodes[i];

    TreeNode *root = buildTree(nodes);

    bool ans = isValidBST(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}
