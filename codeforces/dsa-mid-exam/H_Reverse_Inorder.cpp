#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<long long> &nodes)
{

    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {

        TreeNode *cur = q.front();
        q.pop();

        if (nodes[i] != -1)
        {
            cur->left = new TreeNode(nodes[i]);
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1)
        {
            cur->right = new TreeNode(nodes[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// ================= STUDENT FUNCTION =================
void reverseInorder(TreeNode *root, vector<long long> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    reverseInorder(root->right, ans);
    ans.push_back(root->val);
    reverseInorder(root->left, ans);
}
// ====================================================

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nodes(n);

    for (int i = 0; i < n; i++)
        cin >> nodes[i];

    TreeNode *root = buildTree(nodes);

    vector<long long> ans;

    reverseInorder(root, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}