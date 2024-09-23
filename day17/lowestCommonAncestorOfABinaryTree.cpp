class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        { // if root is one of the two nodes then root itself is lca
            return root;
        }
        TreeNode *lLCA = lowestCommonAncestor(root->left, p, q);  // searching in left subtree
        TreeNode *rLCA = lowestCommonAncestor(root->right, p, q); // searching in right subtree
        if (lLCA == NULL && rLCA == NULL)
        { // if both return null then lca does not exist in this tree, so return null
            return NULL;
        }
        if (lLCA != NULL && rLCA != NULL)
        { // if both return non-null values then current root is the lca
            return root;
        }
        if (lLCA == NULL)
        { // if only right returns non-null value then then that value is lca
            return rLCA;
        }
        return lLCA; // if only left returns non-null value then that is lca
    }
};