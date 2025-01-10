class Solution {
public:
    bool check(int start, int V, vector<int> &color, vector<int> adjLs[]) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adjLs[node]) {
                if(color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjLs[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adjLs[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(V,-1);
        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                if(check(i, V, color, adjLs) == false) return false;
            }
        }
        return true;
    }
};