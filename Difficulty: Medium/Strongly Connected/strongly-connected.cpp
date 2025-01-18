//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, int node) {
        visited[node] = true;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(adj, visited, st, i);
            }
        }
        st.push(node);
    }

    void reverseDfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                reverseDfs(adj, visited, i);
            }
        }
    }

    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        stack<int> st;

        // Step 1: Perform DFS and store nodes in stack
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, st, i);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> adj1(n);
        for (int i = 0; i < n; i++) {
            for (auto j : adj[i]) {
                adj1[j].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transposed graph
        fill(visited.begin(), visited.end(), false); // Reset visited
        int ans = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                reverseDfs(adj1, visited, node);
                ans++;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends