//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int find(int s, int parent[]) {
        if (parent[s] < 0) return s;
        return parent[s] = find(parent[s], parent);
    }
    
    void unionbyweight(int s, int d, int parent[]) {
        int pu = find(s, parent);
        int pv = find(d, parent);
        if (pu != pv) {
            if (parent[pu] < parent[pv]) {
                parent[pu] += parent[pv];
                parent[pv] = pu;
            } else {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }

    int kruskal(vector<pair<int, pair<int, int>>>& edge, int V) {
        int parent[V];
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }

        sort(edge.begin(), edge.end());
        int sum = 0;
        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i].second.first;
            int v = edge[i].second.second;
            int w = edge[i].first;

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu != pv) {
                unionbyweight(u, v, parent);
                sum += w;
            }
        }
        return sum;
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edge;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int w = it[1];

                edge.push_back({w, {u, v}});
            }
        }

        return kruskal(edge, V);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends