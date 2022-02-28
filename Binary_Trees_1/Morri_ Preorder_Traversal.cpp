/*
    Notes-
    We can do it using threaded binary tree
    there are 4 cases- 
    i. if curr->left is not present, push it into ans and go to right
    ii. else- we make prev= curr->left,  and we go to the right most node (prev->right)
    iii. if(prev->right==NULL) we make a thread from that to the curr node and push curr into ans
    iv. if prev->right ==curr , we cut the thread make curr=curr->right 
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};