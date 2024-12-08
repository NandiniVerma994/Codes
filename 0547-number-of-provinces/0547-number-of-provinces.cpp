class Solution {
public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis) {
            vis[node] = 1;
            for(auto it: adjLs[node]) {
                if(!vis[it]) {
                    dfs(it, adjLs, vis);
                }
            }
        }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        //Step 1
        //changing adjacency matrix to list
        int n = isConnected.size();
        vector<int> adjLs[n];// in this adjLs is a list with empty value , adjLs is an array of 5 vectors
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //agr neigbour hoga toh adjacency matrix me 1 marked rhega
                // but dont need to check for 0 ka neighbour 0 h ya nhi
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(n);// vis is a vector of size n each initialised to 0
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;//jitne baar dfs call hogi utne bar counter increase krte
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};