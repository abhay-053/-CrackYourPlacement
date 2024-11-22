//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, int r, int c, int n, int m)
    {
        if(r < 0 || r>=n || c<0 || c>=m || grid[r][c] == '0')return;
        
        grid[r][c] = '0';
        dfs(grid,r-1,c-1, n,m);
        dfs(grid,r-1,c, n,m);
        dfs(grid,r-1,c+1, n,m);
        dfs(grid,r,c-1, n,m);
        dfs(grid,r,c+1, n,m);
        dfs(grid,r+1,c-1, n,m);
        dfs(grid,r+1,c, n,m);
        dfs(grid,r+1,c+1, n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i,j,grid.size(), grid[0].size());
                    count++;
                }
            }
        }
        return count ;;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends