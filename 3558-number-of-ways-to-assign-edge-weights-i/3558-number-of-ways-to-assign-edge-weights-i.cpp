class Solution {
public:
    int maxDepth;
    int mod = 1e9 + 7;
    void dfs(unordered_map<int,vector<int>>& graph, int node, int depth, vector<int>& vis){
        vis[node] = 1;
        maxDepth = max(depth, maxDepth);
        for(auto nd : graph[node]){
            if(!vis[nd]){
                dfs(graph, nd, depth + 1, vis);
            }
        }
    }
    long long binaryExponentiation(long long a, long long b){
        long long res = 1;
        
        while( b > 0){

            if(b & 1){
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }
        return res;

    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        maxDepth = 0;
        for(auto &i: edges){
            int u = i[0];
            int v = i[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int n = edges.size(); 
        vector<int> vis(n+2, 0);
        dfs(graph, 1, 0, vis);

        long long totalWays = binaryExponentiation(2, maxDepth - 1);
        return totalWays % mod;
    }
};