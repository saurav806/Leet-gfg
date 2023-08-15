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
    bool target(TreeNode* root, int targ, int sum){
        if(root == NULL) return false;
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == targ) return true;
        }
        
        return target(root->left, targ, sum+root->val) || target(root->right,targ, sum+=root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return target(root, targetSum, sum);
    }
};