/*
    https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
    make a map with map<int, map<int, multiset<int>>> m;
    make a queue with node and level
    challenging part is printing the answer
*/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* curr=p.first;
            int r=p.second.first;
            int c=p.second.second;
            m[c][r].insert(curr->val);
            if(curr->left!=NULL) q.push({curr->left,{r+1,c-1}});
            if(curr->right!=NULL) q.push({curr->right,{r+1,c+1}});
        }
        for(auto it:m)
        {
            vector<int> v;
            for(auto t:it.second)
            {
                for(auto x:t.second)
                {
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};