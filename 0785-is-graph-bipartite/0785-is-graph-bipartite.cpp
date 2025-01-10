class Solution {
    //if your code fails for larger test cases its mainly bcz of components problem
    bool check(int start, int V, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]) {
                if(color[it] == -1) {
                    //not visited
                    color[it] = !color[node];//paint it with the opposite color of that of the node
                    q.push(it);
                }
                //if visited then check if the adjacent nodes are painted with opposite colors
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        //creating an adjacency list
        vector<int> adj[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(V,-1);
        for(int i=0; i<V; i++) {
            color[i] = -1;
        }
        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                if(check(i, V, adj, color) == false) return false;
            }
        }
        return true;
    }
};