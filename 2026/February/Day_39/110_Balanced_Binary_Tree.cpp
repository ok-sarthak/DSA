//T.C: O(N^2) where N is the number of nodes in the tree. This is because for each node, we are calculating the height of its left and right subtrees, which takes O(N) time in the worst case (when the tree is skewed). Since we do this for every node, the overall time complexity becomes O(N^2).
//S.C: O(N) due to recursive stack space
class Solution {
public:

    int height(TreeNode* root) {

        if(!root)
            return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(leftHeight - rightHeight) > 1) return false;

        return isBalanced(root-> left) && isBalanced(root->right);
    }
};