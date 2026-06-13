class Solution {
public:
    int mod = 1e9+ 7;
    vector<vector<int>> ancestor;
    vector<int> depth;
    int LOG;

    void dfs(unordered_map<int, vector<int>>& tree, int node, int parent, int d){
        ancestor[node][0] = parent;
        depth[node] = d;
        for(auto &nd : tree[node]){
            dfs(tree, nd, node, depth[node] + 1);
        }

    }
    void binaryLifting(unordered_map<int, vector<int>>& tree, int n){
        dfs(tree, 1, -1, 0);
        for(int j = 1; j < LOG; j++){
            for(int node = 1; node <= n; node ++){
                if(ancestor[node][j-1] != -1){
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
    }

    int liftNode(int node,  int k){
        for(int j = LOG-1; j>=0; j--){
            if(k & (1<<j)){
                node = ancestor[node][j];
            }
        }
        return node;
    }

    int LCA(int u, int v){
        int val = 0;

        for(int j = LOG - 1; j >= 0 ; j--){
            if(ancestor[u][j] == -1){
                continue;
            } 

            if(ancestor[u][j] != ancestor[v][j]){
                u = ancestor[u][j];
                v = ancestor[v][j];

                val += (1<<j);
            }
        }

        return val;
    }

    long long binaryExponentiation(long long a, long long b){
        long long res = 1;

        while(b > 0){
            if( b & 1){
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b>>=1;
        }
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> tree;

        for(auto &edge: edges){
            tree[edge[0]].push_back(edge[1]);
        }

        LOG = log2(n) + 1;

        ancestor.resize(n+1, vector<int>(LOG, -1));
        depth.resize(n+1, 0);
        vector<int> ans;
        binaryLifting(tree, n);

        for(auto& query: queries){
            int u = query[0];
            int v = query[1];
            if(u == v){
                ans.push_back(0);
                continue;
            }
            int d1 = depth[u];
            int d2 = depth[v];

            int k = abs(d1-d2);

            if(d1 < d2){
                v = liftNode(v , k);
            } else {
                u = liftNode(u , k);
            }
            
            int jump = 2 * LCA(u, v) + k;
            if(u != v){
                jump += 2;
            }
            int totalWays = 0;

            totalWays = (totalWays +  binaryExponentiation(2ll, 1ll*(jump - 1)) ) % mod;
            ans.push_back(totalWays);
        }

        return ans;
    }
};