class Solution
{

    // Below function can work on any Binary Tree not just BST
    //  ind is index of root in preorder
    // i and j are starting and ending point of tree in inorder i.e. our tree lies between indices i and j (including i and j) in inorder
    TreeNode *getTree(int &ind, vector<int> &preorder, vector<int> &inorder, int i, int j)
    {
        if (ind >= preorder.size() || i > j)
        {
            return NULL;
        }
        for (int k = i; k <= j; k++)
        {
            if (preorder[ind] == inorder[k])
            { // then we can assume that element at kth index in inorder is root. So i to k-1 will be left subtree and k+1 to j is right subtree
                TreeNode *root = new TreeNode(preorder[ind]);
                int temp = ind;
                ind++;
                TreeNode *l = getTree(ind, preorder, inorder, i, k - 1);
                if (k > i && l == NULL)
                { // nodes are present in left subtree but our function is returning NULL, then our assumption is wrong.
                    ind = temp;
                    continue;
                }
                TreeNode *r = getTree(ind, preorder, inorder, k + 1, j);
                if (k < j && r == NULL)
                { // nodes are present in right subtree but our function is returning NULL, then our assumption is wrong.
                    ind = temp;
                    continue;
                }
                // if execution reaches this point then our assumption was right and we can return root with left and right subtrees.
                root->left = l;
                root->right = r;
                return root;
            }
        }
        return NULL;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder;
        for (auto i : preorder)
        {
            inorder.push_back(i);
        }
        sort(inorder.begin(), inorder.end());
        int ind = 0;
        return getTree(ind, preorder, inorder, 0, inorder.size() - 1);
    }
};