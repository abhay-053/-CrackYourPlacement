class Solution {
public:
    typedef long long ll;

	bool isPossible(int mid, int n, unordered_map<int, vector<vector<int>>>& graph, ll k) {

        priority_queue<pair<ll, int>, vector<pair<ll, int>> , greater<pair<ll, int>>> pq;

        pq.push({0, 0});
        vector<ll> dis(n+1, LLONG_MAX);
        dis[0] = 0;
        while(!pq.empty()){
            auto [ct, node] = pq.top();
            pq.pop();


            if(ct > k){
                return false;
            }

            if(node == n - 1){
                return true;
            }

            if(ct > dis[node]){
                continue;
            }
            
            for(auto nei: graph[node]){
                int nd = nei[0];
                long long cost = nei[1];

                if(cost < mid){
                    continue;
                }

                if(dis[nd] > ct + cost){
                    dis[nd] = ct + cost;
                    pq.push({dis[nd], nd});
                }
            }
        }

        return false;
	}

	int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, ll k) {
		int n = online.size();
        unordered_map<int, vector<vector<int>>> graph;

		int l = INT_MAX, r = 0;

		for(auto &edge : edges) {
		    int u = edge[0];
		    int v = edge[1];
		    int w = edge[2];

		    if(!online[u] || !online[v]) 
                continue;
                
		    graph[u].push_back({v, w});
		    l = min(l, w);
		    r = max(r, w);
		}

        int answer = -1;

        while( l<= r){
            int mid = l + (r-l )/2;

            if(isPossible(mid, n, graph, k)){
                answer = mid; 
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

		return answer;
	}
};
