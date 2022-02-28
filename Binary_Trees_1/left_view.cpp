/*
    https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
    Notes: 
    in recursion, Take a variable level
    whenever size of result array==level, push the root
    For left view-> call left recursion first then right
    For right view- we will call root->right first then root->left
*/

void left(Node *root, int level, vector<int> &ans){
    if(root==NULL) return;
    if(level==ans.size())
    ans.push_back(root->data);
    left(root->left,level+1,ans);
    left(root->right,level+1,ans);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
    left(root,0,ans);
    return ans;
}

