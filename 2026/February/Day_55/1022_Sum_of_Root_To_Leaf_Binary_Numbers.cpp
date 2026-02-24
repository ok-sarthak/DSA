// T.C: O(N) where N is the number of nodes in the tree as we need to visit each node once.
// S.C: O(H) where H is the height of the tree and recursion stack space is not considered, otherwise O(N) in worst case when tree is skewed.
class Solution {
public:

    int solve(TreeNode* root, int val) {
        if(!root) return 0;

        val = (2*val) + root->val;

        if(root->left == NULL && root->right == NULL) return val;

        return solve(root->left, val) + solve(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};