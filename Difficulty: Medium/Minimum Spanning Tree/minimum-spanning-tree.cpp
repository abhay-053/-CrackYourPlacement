//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rank, parent;

    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);  
    }

    void unionByWeight(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
                rank[pv] += rank[pu];
            } else {
                parent[pv] = pu;
                rank[pu] += rank[pv];
            }
        }
    }

    int kruskal(vector<vector<int>>& edges, int v) {
        rank.resize(v, 0);
        parent.resize(v);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }

        int sum = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (find(u) != find(v)) {
                unionByWeight(u, v);
                sum += weight;
            }
        }
        return sum;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges; 
        for (int u = 0; u < V; u++) {
            for (auto it : adj[u]) {
                int v = it[0], weight = it[1];
                edges.push_back({u, v, weight});
            }
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        return kruskal(edges, V);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends