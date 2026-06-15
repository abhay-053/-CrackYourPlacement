class Solution {
public:
    vector<vector<int>> ancestor;
    int LOG;
    vector<int> depth;
    vector<vector<int>> freq;

    void dfs(unordered_map<int, vector<pair<int,int>>>& tree, int node, int dpt, int parent, int wt){
        depth[node] = dpt;
        ancestor[node][0] = parent;

        if(parent != -1){
            freq[node] = freq[parent];
            freq[node][wt]++;
        }

        for(auto nd: tree[node]){
            if(parent != nd.first)
                dfs(tree, nd.first, depth[node] + 1, node, nd.second);
        }
    }
    void binaryLifting(unordered_map<int, vector<pair<int,int>>>& tree, int n){
        dfs(tree,0, 0, -1, 0);

        for(int j = 1; j< LOG; j++){
            for(int node = 0; node < n; node++){
                if(ancestor[node][j-1] != -1 )
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
            }
        }
    }

    int LCA(int u, int v){

        if(depth[u] < depth[v]){
            swap(u,v);
        }

        int k = depth[u] - depth[v];

        // lifting node u to same level of node v
        for(int j = 0; j<LOG; j++){
            if(k & (1<<j)){
                u = ancestor[u][j];
            }
        }

        if(u == v){
            return u;
        }

        // node u and node v are at same level 
        // finding lca by lifting both 
        for(int j = LOG -1; j>=0; j--){
            if(ancestor[u][j] == -1){
                continue;
            }

            if(ancestor[u][j] != ancestor[v][j]){
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }

        return ancestor[u][0];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {

        LOG = log2(n) + 1;

        ancestor.resize(n, vector<int>(LOG, -1));
        freq.resize(n, vector<int>(27, 0));
        depth.resize(n, 0);

        unordered_map<int, vector<pair<int,int>>> tree;

        for(auto edge: edges){
            tree[edge[0]].push_back({edge[1], edge[2]});
            tree[edge[1]].push_back({edge[0], edge[2]});
        }

        binaryLifting(tree, n);

        vector<int> ans;
        for(auto query : queries){
            int u = query[0];
            int v = query[1];

            int lca = LCA(u, v);
            int total = 0;
            int maxFreq = 0;
            for(int i = 1; i<= 26; i++){
                int cnt = freq[u][i] + freq[v][i] - 2 * freq[lca][i];

                total += cnt;
                maxFreq = max(maxFreq, cnt);
            }

            ans.push_back(total - maxFreq);
        }
        return ans;
    }
};