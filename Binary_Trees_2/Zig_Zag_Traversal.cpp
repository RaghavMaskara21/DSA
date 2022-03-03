class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        bool rev=false;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int s=q.size();
            vector<int>v(s);
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(!rev) v[i]=curr->val;
                else
                    v[s-1-i]=curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            rev=!rev;
            ans.push_back(v);
        }                   
               
        return ans;
        
    }
};