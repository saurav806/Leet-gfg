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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode *>q;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            int largest = INT_MIN;
            int n = q.size();
            while(n -- > 0){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->val > largest){
                    largest = temp->val;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(largest);
        }
        return ans;
    }
};