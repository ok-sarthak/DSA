//BFS Approach
//Time Complexity: O(N) where N is the number of nodes in the binary tree
//Space Complexity: O(W) where W is the maximum width of the binary tree
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resultLevel = 0;

        queue<TreeNode*> que;
        que.push(root);

        int currentLevel = 1;

        while(!que.empty()) {
            int n = que.size();

            int sum = 0;

            //Traversing all elements of Current Level
            while(n--) {
                TreeNode* temp = que.front();
                que.pop();

                sum += temp->val;

                if(temp->left) {
                    que.push(temp->left);
                }

                if(temp->right) {
                    que.push(temp->right);
                }
            }

            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = currentLevel;
            }

            currentLevel++;
        }

        return resultLevel;
    }
};

//DFS Approach
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

    map<int, int> mp;

    //InOrder DFS
    void DFS(TreeNode* root, int level) {
        if(!root) return;

        mp[level] += root->val;

        DFS(root->left, level+1);
        DFS(root->right, level+1);
    }

    int maxLevelSum(TreeNode* root) {
        mp.clear();

        DFS(root, 1);

        int maxSum = INT_MIN;
        int resultLevel = 0;

        for(auto &i : mp) {
            int level = i.first;
            int sum = i.second;

            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = level;
            }
        }
        return resultLevel;
    }
};