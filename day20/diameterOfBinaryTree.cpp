class Solution
{

    int maxDepth(TreeNode *root, int &diameter) // This function will return maximum depth from given node(root).
    {
        if (root == NULL)
        {
            return 0;
        }
        int lDepth = maxDepth(root->left, diameter);  // max depth from left node
        int rDepth = maxDepth(root->right, diameter); // max depth from right node
        diameter = max(diameter, lDepth + rDepth);    // here we are comparing the maximum diameter passing through current node with final answer.
        return max(lDepth, rDepth) + 1;               // max depth for current node
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = INT_MIN;
        maxDepth(root, diameter);
        return diameter;
    }
};