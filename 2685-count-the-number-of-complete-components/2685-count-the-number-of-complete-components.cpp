class Solution {
public:
    bool bfs(int node, unordered_map<int,vector<int>> &graph, vector<bool>& vis){

        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int e = 0;
        int v = 0;
        while(!q.empty()){
            int n = q.front();
            v++;
            q.pop();
            for(auto &i: graph[n]){
                e++;
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return e == v * (v-1);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, 0);
        int components = 0;
        for(int i = 0; i< n; i++){
            if(!vis[i]){
                if(bfs(i, graph, vis)){
                    components++;
                }
            }
        }

        return components;
    }
};