class Solution {
public:
    void dfs(vector<int> &vis, vector<vector<int>>& adjLs, int node) {
        vis[node] = 1;
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(vis, adjLs, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                }
            }
        }
        //adjLs[[2],[1],[]]
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                count++;
                dfs(vis, adjLs, i);
            }
        }
        return count;
    }
};