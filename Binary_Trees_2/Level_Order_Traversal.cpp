/*
    https://leetcode.com/problems/binary-tree-level-order-traversal/
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(q.size()>1){            
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                q.push(NULL);
                ans.push_back(v);
                v.clear();
            }else{
            v.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            }
            
        }
        ans.push_back(v);
        return ans;
    }
};