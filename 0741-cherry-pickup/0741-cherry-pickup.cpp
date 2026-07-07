class Solution {
public:
    int n, m;
    int dp[51][51][51];
    int solve(vector<vector<int>>& grid, int i1, int j1, int i2){

        int j2 = i1 + j1 - i2;
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1){
            return INT_MIN;
        }

        if(i1 == n-1 && j1 == n-1){
            return grid[i1][j1];
        }

        if(dp[i1][j1][i2] != -1){
            return dp[i1][j1][i2];
        }

        int a = solve(grid, i1 + 1, j1, i2 + 1 );
        int b = solve(grid, i1 + 1, j1, i2);
        int c = solve(grid, i1 , j1 + 1, i2 + 1 );
        int d = solve(grid, i1 , j1 + 1, i2 );

        int ans = max({a,b,c,d});

        if(ans == INT_MIN){
            return dp[i1][j1][i2] = INT_MIN;
        }
        int cur = grid[i1][j1] ;

        if(i1 != i2 || j1 != j2){
            cur += grid[i2][j2];
        }

        return dp[i1][j1][i2] = cur + ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        int ans = solve(grid, 0, 0, 0);
        return ans < 0 ? 0 : ans ;
    }
};