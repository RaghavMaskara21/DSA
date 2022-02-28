/* 
    https://leetcode.com/problems/binary-tree-inorder-traversal
    Notes-
    Take a stack and push all left elements into the stack
    take out topmost element and print it
    set curr to curr->right
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*> s;
        vector<int> ans;
        while (curr!=NULL || s.empty()==false){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            ans.push_back(curr->val);
            s.pop();
            curr=curr->right;            
        }
        return ans;        
    }
};