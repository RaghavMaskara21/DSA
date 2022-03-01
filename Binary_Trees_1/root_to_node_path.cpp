/*
https://www.interviewbit.com/problems/path-to-given-node/
Notes-
    - We take a bool recursive function
- if root is pointing to NULL, we return false 
- Now we first push the node to our ans
-Then we check whether the current node is the target node or not, if yes, return true
-If not, then we recursively call its left and right child-, If any one of them returns true,we return true
- we pop out the current node from the ans and return false.
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