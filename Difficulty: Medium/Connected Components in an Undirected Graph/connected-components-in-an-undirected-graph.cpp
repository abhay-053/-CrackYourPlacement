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

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); 
        }
        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){

            if (!visited[i]) {
                vector<int> component;
                collectComponent(adj, visited,i, component);
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