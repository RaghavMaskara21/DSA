/*
    https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    Note-
    - we create a queue with pair<node,int>
    - we assign 1 for preorder, 2 for inorder, 3 for postorder
    - push {curr,1} in queue
    - 3 cases - if val is 1 - then pop [push in preorder] and push curr with val 2 and curr->left with val 1
              - if val is 2 - then pop [push in inorder]and push curr with val 3 and curr->right with val 1
              - if val is 3 - then just pop [push in postorder]
*/

void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({
    root,
    1
  });
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);
      if (it.first -> left != NULL) st.push({it.first -> left, 1});      
    }
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);
      if (it.first -> right != NULL) st.push({it.first -> right,1});
    }    
    else {
      post.push_back(it.first -> data);
    }
  }
}


/*
    recursive easy method
*/

void helper(TreeNode *root, vector<vector<int>>&v){
if(root == NULL)return;
v[1].push_back(root->data); // for Preorder
helper(root->left, v);
v[0].push_back(root->data); // for Inorder
helper(root->right, v);
v[2].push_back(root->data); // for postorder
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
vector<vector<int>>v(3);
helper(root, v);
return v;
}