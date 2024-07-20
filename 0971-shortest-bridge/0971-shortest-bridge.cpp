class Solution {
public:
    int bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid, int n, int m)
    {
        int dc[] = {-1, 0, 1, 0};
        int dr[] = {0, 1, 0, -1};
        int ans = 0;
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                auto t = q.front();
                q.pop();
                int r = t.first;
                int c = t.second;
                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 2)
                    {
                        if(grid[nr][nc] == 1)
                        {
                            return ans;
                        }
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int u, int v, int n, int m, queue<pair<int,int>>& q)
    {
        if(u < 0 || u >= n || v < 0 || v >= m || grid[u][v] != 1)
        {
            return;
        }

        grid[u][v] = 2;
        q.push({u, v});
        dfs(grid, u + 1, v, n, m, q);
        dfs(grid, u - 1, v, n, m, q);
        dfs(grid, u, v + 1, n, m, q);
        dfs(grid, u, v - 1, n, m, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid, i, j, n, m, q);
                    return bfs(q, grid, n, m);;
                }
            }
        }

        
        return 0;
    }
};
