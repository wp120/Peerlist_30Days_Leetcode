class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root == NULL)
        {
            return {};
        }
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> levelVector; // to store current level nodes' values.
            while (sz--)
            {
                TreeNode *n = q.front();
                q.pop();
                levelVector.push_back(n->val);
                if (n->left != NULL)
                {
                    q.push(n->left);
                }
                if (n->right != NULL)
                {
                    q.push(n->right);
                }
            }
            ans.push_back(levelVector); // storing current level to our answer.
        }
        return ans;
    }
};