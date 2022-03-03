/*
    https://leetcode.com/problems/balanced-binary-tree/
*/
class Solution {
public:
    
    bool isBalanced(TreeNode* root) {
        return postorder(root)==-1?false:true;
    }
    
    int postorder(TreeNode* root){
        if(root==NULL) return 0;
        int lh=postorder(root->left);
        if(lh==-1) return -1;
        int rh=postorder(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
};