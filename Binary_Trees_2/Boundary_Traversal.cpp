void left(TreeNode<int>*root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
 	ans.push_back(root->data);
    if(root->left!=NULL) left(root->left,ans);
    else
        left(root->right,ans);
}
void bottom(TreeNode<int>*root,vector<int>&ans){
    if(root==NULL) return;
    bottom(root->left,ans);
    if(root->left==NULL && root->right==NULL) 
        ans.push_back(root->data);
    bottom(root->right,ans);
}

void right(TreeNode<int>*root, vector<int> &temp){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
 	temp.push_back(root->data);
    if(root->right!=NULL) right(root->right,temp);
    else
        left(root->left,temp);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    if(root==NULL) return {};
    vector<int> ans;
    if(root->left!=NULL || root->right!=NULL) ans.push_back(root->data);
    left(root->left,ans);
    bottom(root,ans);
    vector<int> temp;
    right(root->right,temp);
    
    if(temp.size()>0){
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
    }
    return ans;
}