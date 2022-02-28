/*
https://www.interviewbit.com/problems/path-to-given-node/

*/
bool path(TreeNode* curr, int B, vector<int> &ans){
    if(!curr) return false;
    ans.push_back(curr->val);
    if(curr->val==B){        
        return true;
    }
    if( path(curr->left,B,ans) || path(curr->right,B,ans))
    return true;
    ans.pop_back();
    return false;

}

vector<int> Solution::solve(TreeNode* A, int B) {
vector<int> ans;
if(A==NULL) return ans;
path(A,B,ans);
return ans;

}