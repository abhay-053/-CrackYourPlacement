//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(unordered_map<int, vector<int>>&mp, int node, vector<bool>&vis, int parent)
    {
        vis[node]  = true;
        for(auto adjnode : mp[node])
        {
            if(!vis[adjnode])
            {
                if(dfs(mp, adjnode, vis, node) == true){
                    return true;
                }
            }
            else if (parent != adjnode)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<adj.size();i++)
        {
            for(auto j : adj[i])
            {
                mp[i].push_back(j);
            }
        }
        
        vector<bool>vis(adj.size(),false);
        for(int i=0;i<adj.size();i++)
        {
            if(!vis[i])
            {
                if(dfs(mp, i, vis,-1) == true){
                    return true;
                }
                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends