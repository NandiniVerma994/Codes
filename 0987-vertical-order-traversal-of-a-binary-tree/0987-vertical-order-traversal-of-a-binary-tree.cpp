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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset <int>>> nodes;//verticals, levels, nodes 
        queue<pair<TreeNode*, pair<int,int>>> queue;
        queue.push({root,{0,0}});
        while(!queue.empty()) {
            auto p = queue.front();
            queue.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node -> left) {
                queue.push({node->left, {x-1,y+1}});
            }
            if(node -> right) {
                queue.push({node -> right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p: nodes) {
            vector<int> col;
            for(auto q: p.second) {
                for(auto it : q.second) {//multiset me jyada elements v ho skta h   
                    col.push_back(it);
                }
            }//after traversing the entire levels  
            ans.push_back(col);
        }
        return ans;

    }
};