/*
    https://leetcode.com/problems/binary-tree-postorder-traversa
    Notes-
    Take 2 stacks
    push root in 1 stack
    while s1 not empty - pop element and put in s2
    push its left and right node in s1
    after loop put all elements from stack to ans
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {        
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s1,s2;
        TreeNode* curr=root;
        s1.push(curr);
        while(s1.empty()==false){            
            curr=s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left!=NULL) s1.push(curr->left);
            if(curr->right!=NULL) s1.push(curr->right);            
        }
        while(s2.empty()==false){
            curr=s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};