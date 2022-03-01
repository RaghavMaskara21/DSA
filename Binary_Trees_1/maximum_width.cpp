/*
    https://leetcode.com/problems/maximum-width-of-binary-tree/
    - Make a queue {root,0}
- Do level order traversal.
- In the level order traversal we set another loop to run for the size of the queue, so that we visit the same level nodes inside it.
- Before a level starts, we use a variable(say curMin) to store the index of the first node.
- We assign an index to every node, and to its children as described above.
- When the inner loop is at the first node of a level, we store its index in another variable(sayleftMost)
- When the inner loop is at the last node of a level, we store its index in another variable(say rightMost)
- After a level in the outer loop, we calculate the width of the level as (rightMost – leftMost +1).
- We return the maximum width as the answer.
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        long long int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long int mmin = q.front().second;    //to make the id starting from zero
            long long int first,last;
            for(int i=0; i<size; i++){
                long long int cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                if(node->left)
                    q.push({node->left, cur_id*2+1});
                if(node->right)
                    q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return (int)ans;
    }
};