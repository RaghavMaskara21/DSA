/*
    https://leetcode.com/problems/diameter-of-binary-tree/
*/
class Solution {
public:
    
    int height(TreeNode* curr, int &dia){
        if(curr==NULL) return 0;
        int lh=height(curr->left,dia);
        int rh=height(curr->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
         height(root,dia);
        return dia;
    }
};