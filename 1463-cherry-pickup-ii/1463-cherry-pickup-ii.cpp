class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> prev(col + 1, vector<int>(col +1));
        
        prev[0][col-1] = (col == 1) ? grid[0][0] : grid[0][0] + grid[0][col - 1];

        for(int i = 1; i< row; i++){
            vector<vector<int>> cur(col + 1, vector<int>(col + 1));

            for(int j1 = 0; j1 <= min(i, col-1); j1++){
                for(int j2 = max(0, col - 1 - i) ; j2 < col; j2++){

                    int prevMax = 0;

                    for(int c1 = max(j1 - 1 , 0) ; c1 <= min(j1 + 1, col - 1) ; c1++){
                        for(int c2 = max(j2 - 1, 0); c2 <= min(j2 + 1, col -1 ); c2++){
                            prevMax = max(prevMax, prev[c1][c2]);
                        }
                    }

                    if(j1 != j2){
                        cur[j1][j2] = prevMax + grid[i][j2] + grid[i][j1];
                    } else {
                        cur[j1][j2] = prevMax + grid[i][j1];
                    }
                }
            }

            prev = cur;
        }
        
        int ans = 0;
        for(int i = 0; i < col; i++){
            for(int j = 0; j< col ;j++){
                ans = max(prev[i][j], ans);
            }
        }
        return ans;
    }
};