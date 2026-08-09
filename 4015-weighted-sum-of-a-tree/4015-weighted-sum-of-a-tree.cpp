class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<int, vector<int>> graph;

        int n = parent.size();
        for(int i = 1; i < n; i++){
            graph[parent[i]].push_back(i);
        }

        queue<int> q;

        q.push(0);

        int h = 0;
        vector<bool> vis(n, false);
        vis[0] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int t = q.front();
                q.pop();
                for(auto node: graph[t]){
                    if(!vis[node]){
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
            h++;
        }
        q.push(0);
        long long sum = 0;
        vis.clear();
        vis.resize(n, 0);
        vis[0] = true;
        int d = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int t = q.front();
                q.pop();
                sum += nums[t] * 1ll * (h - d + 1);
                for(auto node: graph[t]){
                    if(!vis[node]){
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
            d++;
        }

        return sum;
    }
};