class Solution {
public: 
    void dfs(int src, int node, vector<int> &vis, vector<vector<int>> &ans, unordered_map<int,vector<int>> &graph){
        vis[node] = 1;

        for(auto nd : graph[node]){
            if(!vis[nd]){
                ans[nd].push_back(src);
                dfs(src, nd, vis, ans, graph);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);

        unordered_map<int,vector<int>> graph;

        for(auto &edge: edges){
            int u = edge[0]; 
            int v = edge[1];

            graph[u].push_back(v);
        }

        for(int i = 0; i< n; i++){
            vector<int> vis(n, 0);
            dfs(i, i, vis, ans, graph);
        }
        return ans;
    }
};