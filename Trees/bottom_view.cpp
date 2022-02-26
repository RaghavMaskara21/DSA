/*
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Notes- we will draw lines vertically.
    -store vertical level and the value in a map
    -make a queue with node and vertical levels
    -do level order traversal and update the value of the map
*/


vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if(!root) return res;
        map<int,int> m;
        queue<pair<Node* , int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* curr=p.first;
            int level=p.second;
            m[level]=curr->data;
            if(curr->left!=NULL) q.push({curr->left,level-1});
            if(curr->right!=NULL) q.push({curr->right,level+1});
            
        }
        for(auto it:m){
            res.push_back(it.second);
        }
        return res;
    }