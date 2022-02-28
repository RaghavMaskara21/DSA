/* 
    https://leetcode.com/problems/binary-tree-preorder-traversal
    Notes-
    take a stack and print the current->left node and push it into stack
    pop it
    set curr to curr->right
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