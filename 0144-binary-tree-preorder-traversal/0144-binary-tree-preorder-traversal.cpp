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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(node != NULL || !st.empty()) {
            while(node != NULL) {
                pre.push_back(node->val);
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return pre;
    }
};