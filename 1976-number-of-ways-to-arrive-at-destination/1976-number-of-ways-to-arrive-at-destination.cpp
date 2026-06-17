#define pp pair<long long, int>
const int MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pp>> graph;

        for(auto &i: roads){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto [dis, u] = pq.top();
            pq.pop();

            if(dis > dist[u]){
                continue;
            }

            for(auto node : graph[u]){
                int v = node.first;
                int d = node.second;
                if(dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                    ways[v] = ways[u];
                    pq.push({dist[v] , v});

                } else if(dist[u] + d == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                    cout<<"hi"<<v<<endl;
                }
            }
        }

        return ways[n-1];
    }
};