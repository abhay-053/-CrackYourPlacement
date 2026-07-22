class Solution {
public:
    #define P pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;

        for(auto i: times){
            int u = i[0];
            int v = i[1];
            int w = i[2];

            graph[u].push_back({v, w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, k});
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            if(dis[node] < time ){
                continue;
            }

            for(auto &nd: graph[node]){
                int node1 = nd.first;
                int t = nd.second;
                if(dis[node1] > time + t){
                    dis[node1] = time + t;
                    pq.push({dis[node1], node1});
                }
            }
        }
        int ans = 0;
        // for(auto i: dis){cout<<i<<" ";}
        for(int i = 1; i<=n; i++){
            if(dis[i] != INT_MAX){
                ans= max(ans, dis[i]);
            } else {
                return -1;
            }
        }

        return ans;
    }
};