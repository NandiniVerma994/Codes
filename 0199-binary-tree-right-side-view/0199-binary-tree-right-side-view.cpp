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
    void recursionRight(TreeNode* root, int level, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        if(result.size() == level) {//first time result ka size is 0
            result.push_back(root-> val);
        }
        recursionRight(root->right, level+1, result);
        recursionRight(root->left, level+1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
       recursionRight(root, 0, result);
       return result;
    }
};