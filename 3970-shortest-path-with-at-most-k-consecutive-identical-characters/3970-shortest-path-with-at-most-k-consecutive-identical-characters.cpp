class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto &edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> dis(n,vector<int>(k + 1, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        dis[0][1] = 0;
        pq.push({0, 0, 1}); 

        while(!pq.empty()){
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dis[u][cnt]){
                continue;
            }

            for(auto &nd : graph[u]){
                int v = nd.first;
                int w = nd.second;

                int newCnt;

                if(labels[u] == labels[v]){
                    newCnt = cnt + 1;
                } else {
                    newCnt = 1;
                }

                if(newCnt > k){
                    continue;
                }

                if(d + w < dis[v][newCnt]){
                    dis[v][newCnt] = d + w;
                    pq.push({dis[v][newCnt], v, newCnt});
                }
            }
        }

        int ans = INT_MAX;

        for(int cnt = 1; cnt <= k; cnt++){
            ans = min(ans, dis[n-1][cnt]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};