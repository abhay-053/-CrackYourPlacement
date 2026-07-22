class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        unordered_map<int, vector<pair<int,double>>> graph;
        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        while(!pq.empty()){
            auto [p, node] = pq.top();
            pq.pop();

            if(prob[node] > p){
                continue;
            }

            for(auto nd: graph[node]){
                double p1= nd.second;
                int node1 = nd.first;

                if(prob[node1] < p1 * p){
                    prob[node1] = p1 * p;
                    pq.push({prob[node1], node1});
                }
            }
        }
       
        return prob[end_node];
    }
};