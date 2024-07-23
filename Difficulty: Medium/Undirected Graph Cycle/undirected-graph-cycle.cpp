//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(int u, vector<int> adj[], vector<bool>& vis)
    {
        
        queue<pair<int,int>> q;
        q.push({u,-1});
        vis[u] = true;
        while(!q.empty())
        {
            int u = q.front().first;
            int p = q.front().second;
            q.pop();
            for(auto v : adj[u])
            {
                if(!vis[v])
                {
                    q.push({v,u});
                    vis[v] = true;
                }
                else if(v!=p)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> vis(V,false);
       
       for(int i=0;i<V;i++)
       {
           if(!vis[i] && bfs(i,adj,vis))
            return true;
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
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends