class Solution {
public:
    void bfs(int row, int col , vector<vector<char>> &grid)
    {
        int dc[]={-1,0,1,0};
        int dr[]={0,1,0,-1};
        queue<pair<int,int>> q;
        grid[row][col]='0';
        q.push({row,col});
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int r = tmp.first;
            int c = tmp.second;
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if( nr >=0 && nr < grid.size() && nc >= 0 && nc<grid[0].size() && grid[nr][nc] != '0')
                {
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size();
        int column=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(grid[i][j]== '1')
                {
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};