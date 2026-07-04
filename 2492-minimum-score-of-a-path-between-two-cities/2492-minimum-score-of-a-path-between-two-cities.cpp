class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int, int>>> graph;

        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int d = road[2];

            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        queue<pair<int,int>> q;

        q.push({1, INT_MAX});
        vector<bool> vis(n+1, false);
        int minEdgeWeight = INT_MAX;
        while(!q.empty()){
            auto [node, dis] = q.front();

            minEdgeWeight = min(minEdgeWeight, dis);
            q.pop();

            if(vis[node]){
                continue;
            }

            vis[node] = true;
            for(auto i: graph[node]){
                q.push({i.first, i.second});
            }
        }

        return minEdgeWeight;
    }
};