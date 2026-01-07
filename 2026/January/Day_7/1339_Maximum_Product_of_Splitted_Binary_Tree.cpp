/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Time Complexity: O(N) where N is the number of nodes in the binary tree
//Space Complexity: O(H) where H is the height of the binary tree
class Solution {
public:

    long SUM = 0; //Total Sum of the Tree
    long maxP;

    int totalSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        int sum = root->val + leftSubtreeSum + rightSubtreeSum;

        return sum;
    }

    int find(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSum = find(root->left);
        int rightSum = find(root->right);
        long subTreeSum = root->val + leftSum + rightSum;

        long remainingSubTreeSum = SUM - subTreeSum;

        maxP = max(maxP, subTreeSum*remainingSubTreeSum);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;

        maxP = 0;

        SUM = totalSum(root);

        find(root);

        return maxP%(1000000007);
    }
};

//Single Pass Approach
//Time Complexity: O(N) where N is the number of nodes in the binary tree
//Space Complexity: O(H) where H is the height of the binary tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    long SUM = 0; //Total Sum of the Tree
    long maxP;

    int totalSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        int subTreeSum = root->val + leftSubtreeSum + rightSubtreeSum;

        long remainingSubTreeSum = SUM - subTreeSum;

        maxP = max(maxP, subTreeSum*remainingSubTreeSum);

        return subTreeSum;
    }

    // int find(TreeNode* root) {
    //     if(root == NULL) return 0;

    //     int leftSum = find(root->left);
    //     int rightSum = find(root->right);
    //     long subTreeSum = root->val + leftSum + rightSum;

    //     long remainingSubTreeSum = SUM - subTreeSum;

    //     maxP = max(maxP, subTreeSum*remainingSubTreeSum);

    //     return subTreeSum;
    // }

    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;

        maxP = 0;

        SUM = totalSum(root);

        totalSum(root);

        return maxP%(1000000007);
    }
};