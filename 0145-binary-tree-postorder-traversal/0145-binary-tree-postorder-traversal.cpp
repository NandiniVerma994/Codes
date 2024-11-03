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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* lastVisited = NULL;
        TreeNode* node = root;
        vector<int> post;
        stack<TreeNode*> st;
        while(node != NULL && lastVisited != root) {
            while(node != NULL && lastVisited != node) {
                st.push(node);
                node = node -> left;
            }
            node = st.top();
            st.pop();
            if(node->right == NULL || node->right == lastVisited) {
                post.push_back(node->val);
                lastVisited = node;
            }
            else {
                st.push(node);
                node = node->right;
            }
        }
        return post;
    }
};