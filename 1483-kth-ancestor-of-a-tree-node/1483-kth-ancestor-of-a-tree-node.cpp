class TreeAncestor {
public:
    unordered_map<int,vector<int>> tree;
    vector<vector<int>> ancestor;
    int LOG;
    void dfs(int node, int parent){
        ancestor[node][0] = parent;

        for(auto nxt: tree[node]){
            dfs(nxt, node);
        }
    }
    void createAncestorTable(int n){
        dfs(0, -1);
        for(int j = 1; j<LOG; j++){
            for(int node = 0; node < n; node++){
                if(ancestor[node][j-1] != -1){
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        for(int i = 1; i< n; i++){
            tree[parent[i]].push_back(i);
        }
        LOG = log2(n) + 1;
        ancestor.resize(n,vector<int>(LOG , -1));
        createAncestorTable(n);
    }
    
    int getKthAncestor(int node, int k) {
        int aNode = node;
        for(int i = 0 ; i<LOG; i++){
            if(aNode == -1)
                return -1;

            if(k & (1 << i)){
                aNode = ancestor[aNode][i];
            }
        }
        return aNode;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */