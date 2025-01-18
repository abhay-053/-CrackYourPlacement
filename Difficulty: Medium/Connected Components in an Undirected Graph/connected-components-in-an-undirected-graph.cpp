//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

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

    void collectComponent(vector<vector<int>>& adj, vector<bool>& visited, int node, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (auto i : adj[node]) {
            if (!visited[i]) {
                collectComponent(adj, visited, i, component);
            }
        }
    }

    vector<vector<int>> connectedcomponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Since it's an undirected graph
        }

        stack<int> st;
        vector<bool> visited(n, false);

        // Step 1: Perform DFS to fill stack with nodes based on finish time
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
        vector<vector<int>> ans;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                vector<int> component;
                collectComponent(adj1, visited, node, component);
                sort(component.begin(), component.end());
                ans.push_back(component);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends