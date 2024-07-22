//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dr[8] ={-1,-1,-1,0,0,1,1,1};
    int dc[8] ={-1,0,1,1,-1,-1,0,1};
    void dfs(vector<vector<char>>& grid, int row, int col, int n, int m)
    {
        grid[row][col]='0';
        
        
        
        for(int i=0;i<8;i++)
        {
            int nr= row+dr[i];
            int nc= col+dc[i];
            
            if(nr>=0 && nr<n && nc >=0 && nc<m && grid[nr][nc] != '0')
            {
                dfs(grid,nr,nc,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
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
    }
    return 0;
}
// } Driver Code Ends