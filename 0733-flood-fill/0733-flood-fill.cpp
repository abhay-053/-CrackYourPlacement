class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int color1)
    {
        if(sr < 0 || sc < 0 || sr>= image.size() || sc >= image[0].size() || image[sr][sc] != color1|| image[sr][sc] == color)
            return ;

        image[sr][sc] = color;
        
        dfs(image, sr+1, sc, color ,color1);
        dfs(image, sr-1, sc, color ,color1);
        dfs(image, sr, sc+1, color ,color1);
        dfs(image, sr, sc-1, color ,color1);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int color1 = image[sr][sc];
        dfs(image, sr,sc,color,color1);
        return image;
    }
};