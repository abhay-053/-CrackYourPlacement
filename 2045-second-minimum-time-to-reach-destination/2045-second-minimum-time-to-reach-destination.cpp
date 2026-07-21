class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> dis_1(n + 1, INT_MAX);
        vector<int> dis_2(n + 1, INT_MAX);

        unordered_map<int,vector<int>> graph;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});

        while(!pq.empty()){
            auto [timePassed, node] = pq.top();
            pq.pop();

            if(node == n && dis_2[node] != INT_MAX){
                return dis_2[node];
            }

            int signal = timePassed/ change;

            if(signal % 2){
                timePassed = (1 + signal) * change;
            }

            for(auto &nd : graph[node]){
                if(dis_1[nd] > timePassed + time ){
                    dis_2[nd] = dis_1[nd];
                    dis_1[nd] = timePassed + time;
                    pq.push({dis_1[nd], nd});
                } else if( dis_2[nd] > timePassed + time && dis_1[nd] != timePassed + time){
                    dis_2[nd] = timePassed + time;
                    pq.push({dis_2[nd], nd});
                }
            }
        }

        return -1;
    }
};