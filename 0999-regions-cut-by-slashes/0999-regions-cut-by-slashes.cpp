class Solution {
public:
    void dfs( int i, int j, vector<vector<int>>&mat, int &ans)
    {
        int n=mat.size();
        int m=mat[0].size();
        if(i<0 || j<0 || i>=n || j>= m || mat[i][j]== 1 )
            return;
        mat[i][j]=1;
        dfs(i+1,j,mat,ans);
        dfs(i,j+1, mat,ans);
        dfs(i-1,j,mat,ans);
        dfs(i,j-1,mat,ans);
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int r =grid.size();
        int c = grid[0].size();
        int ans=0;
        vector<vector<int>>mat(r*3, vector<int>(c*3,0));
        for ( int i = 0; i < r ; i++)
        {
            for(int j =0 ; j<c; j++)
            {
                if(grid[i][j] == '/')
                {
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if( grid[i][j] == '\\')
                {
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }
        //island find krte jaise vaise hi krna hai bs ab
        for(int i=0;i< mat.size();i++)
        {
            for(int j= 0 ;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    dfs(i,j,mat,ans);
                    ans++;
                }
            }
        }
        return ans;
    }
};