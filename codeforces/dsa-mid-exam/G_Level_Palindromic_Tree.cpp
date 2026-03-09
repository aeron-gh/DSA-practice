#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoll(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (nodes[i] != "null")
        {
            cur->left = new TreeNode(stoll(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            cur->right = new TreeNode(stoll(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// ================= STUDENT FUNCTION =================
bool isLevelPalindromic(TreeNode *root)
{

    queue<TreeNode *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int sz = qu.size();
        vector<int> vec;
        for (int i = 0; i < sz; i++)
        {
            auto curr = qu.front();
            vec.push_back(curr->val);
            qu.pop();
            if (curr->left)
            {
                qu.push(curr->left);
            }
            if (curr->right)
            {
                qu.push(curr->right);
            }
        }
        
        vector<int> cpvec;
        cpvec = vec;
        reverse(cpvec.begin(), cpvec.end());
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != cpvec[i])
            {
                return false;
            }
        }
    }
    return true;
}
// ====================================================

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

    bool ans = isLevelPalindromic(root);

    cout << (ans ? "TRUE" : "FALSE") << '\n';
}