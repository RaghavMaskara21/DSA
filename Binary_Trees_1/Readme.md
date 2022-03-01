# Binary Trees 1 - Short Notes

## Inorder Traversal (Iterative)

-Take a stack and push all left elements into the stack
-take out topmost element and print it
-set curr to curr->right

## Preorder Traversal (Iterative)

-take a stack and print the current->left node and push it into stack
-pop it
-set curr to curr->right

## Postorder Traversal (Iterative)

- Take 2 stacks
- push root in 1 stack
- while s1 not empty - pop element and put in s2
- push its left and right node in s1
- after loop put all elements from stack to ans

## Morris Inorder Traversal

- We can do it using threaded binary tree
- There are 4 cases-
  i. if curr->left is not present, push it into ans and go to right
  ii. else- we make prev= curr->left, and we go to the right most node (prev->right)
  iii. if(prev->right==NULL) we make a thread from that to the curr node
  iv. if prev->right ==curr , we cut the thread and push curr into ans, then make curr=curr->right

## Morris Preorder Traversal

- We can do it using threaded binary tree
- There are 4 cases-
  i. if curr->left is not present, push it into ans and go to right
  ii. else- we make prev= curr->left, and we go to the right most node (prev->right)
  iii. if(prev->right==NULL) we make a thread from that to the curr node and push curr into ans
  iv. if prev->right ==curr , we cut the thread make curr=curr->right

## Left View

- in recursion, Take a variable level
- whenever size of result array==level, push the root
- For left view-> call left recursion first then right
- For right view- we will call root->right first then root->left

## Bottom View

- we will draw lines vertically.
- create a map for level and value ; and a queue for node and level
- do level order traversal and update the value of the map everytime we traverse

## Top View

- we will draw lines vertically.
- create a map for level and value ; and a queue for node and level
- do level order traversal and update the value of the map only the first time

## Preorder, Inorder, Postorder in single traversal

- we create a queue with pair<node,int>
- we assign 1 for preorder, 2 for inorder, 3 for postorder
- push {curr,1} in queue
- 3 cases
- if val is 1 - then pop [push in preorder] and push curr with val 2 and curr->left with val 1
- if val is 2 - then pop [push in inorder]and push curr with val 3 and curr->right with val 1
- if val is 3 - then just pop [push in postorder]

## Vertical Order Traversal

- make a map with map<int, map<int, multiset<int>>> m;
- make a queue with node and level
- challenging part is printing the answer

## Root to node path in binary Tree

- We take a bool recursive function
- if root is pointing to NULL, we return false
- Now we first push the node to our ans
  -Then we check whether the current node is the target node or not, if yes, return true
  -If not, then we recursively call its left and right child-, If any one of them returns true,we return true
- we pop out the current node from the ans and return false.

## Max width of a binary tree

- Make a queue {root,0}
- Do level order traversal.
- In the level order traversal we set another loop to run for the size of the queue, so that we visit the same level nodes inside it.
- Before a level starts, we use a variable(say curMin) to store the index of the first node.
- We assign an index to every node, and to its children as described above.
- When the inner loop is at the first node of a level, we store its index in another variable(sayleftMost)
- When the inner loop is at the last node of a level, we store its index in another variable(say rightMost)
- After a level in the outer loop, we calculate the width of the level as (rightMost – leftMost +1).
- We return the maximum width as the answer.
