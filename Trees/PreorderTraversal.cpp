/* 
    https://leetcode.com/problems/binary-tree-preorder-traversal
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr!=NULL || s.empty()==false){
            while(curr!=NULL){
                s.push(curr);
                ans.push_back(curr->val);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            curr=curr->right;
        }
        return ans;
    }
};