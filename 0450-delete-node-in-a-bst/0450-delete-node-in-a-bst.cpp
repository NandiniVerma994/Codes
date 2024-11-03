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
    TreeNode* findLastRight(TreeNode* root) {
        if(root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }

    TreeNode* helper(TreeNode* root) {//root is 3 node to be deleted
        if(root->left == NULL) return root->right;//agr left wala nhi h toh
        else if(root->right == NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;//mtlb 3 ka left
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            //if root only does not exist then how will key exist
            return NULL;
        }
        if(root->val == key) {
            return helper(root);
        }
        //dummy will store the address of the root which after modifying will be returned
        TreeNode* dummy = root;
        while(root != NULL) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    //we need to delete it
                    //root->left means 5 ka left me 2 join hona chahiye
                    root->left  = helper(root->left);//helper(3)-->node to be deleted          
                    break;
                }
                else {
                    //if key is not found
                    root = root->left;
                }
            }
            //similarly if node to be deleted is at right
            else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            } 
        }
        return dummy;
    }
};