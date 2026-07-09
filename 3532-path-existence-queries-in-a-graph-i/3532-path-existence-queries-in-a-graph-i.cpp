class DSU {
    
    vector<int> rank;
    vector<int> parent;

    public:
    DSU( int n) : rank(n, 0) , parent(n) {
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unionByRank(int u, int v){

        int pu = find(parent[u]);
        int pv = find(parent[v]);

        if(pu != pv){
            
            if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            } else if(rank[pv] > rank[pu]){
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
            dsu.unionByRank(i, i - 1);
        }

        vector<bool> ans;
        for(auto &i : queries){
            
            int u = i[0];
            int v = i[1];
            int pu = dsu.find(u);
            int pv = dsu.find(v);
            if(pu == pv){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};