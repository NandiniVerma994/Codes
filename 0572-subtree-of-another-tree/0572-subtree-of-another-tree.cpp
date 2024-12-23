/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        else if(p == NULL || q == NULL) {
            return false;
        }
        return (p->val == q->val) && 
           isSameTree(p->left, q->left) &&  
           isSameTree(p->right, q->right);

        return false; 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot != NULL) {
            return false;
        }

        
        if(isSameTree(root, subRoot)) {
            return true;
        } 
        
        
        return (isSubtree(root->left, subRoot) || 
            isSubtree(root->right, subRoot)) ;   
          
    }
};