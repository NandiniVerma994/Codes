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
    struct TreeNode* findLastRight(struct TreeNode* root) {
        while(root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key == root->val) {
            //has no children
            if(root->left == NULL && root->right == NULL) {
                delete(root);
                return NULL;
            }
            else if(root->left == NULL) {
                struct TreeNode* temp = root->right;
                delete(root);
                return temp;//we are returning it to the recursive call so  stating that the new left is ....
            }
            else if(root->right == NULL) {
                struct TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else {//agr left aur right dono me value h
                //we have to connect the right part of the key to the bottom rightmost part of the left subtree of the key
                struct TreeNode* lastRtOfLeftSubtree = findLastRight(root->left);
                lastRtOfLeftSubtree->right = root->right;
                struct TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
        }
        return root;
    }
};