class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row, col;

        for(int i=0;i<n;i++){
            int k = INT_MAX;
            for(int j=0;j< m;j++){
                k = min(k , matrix[i][j]);
            }
            row.push_back(k);
        }
        for(int i=0;i<m;i++){
            int k = INT_MIN;
            for(int j=0;j<n;j++){
                k = max(k , matrix[j][i]);
            }
            col.push_back(k);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(matrix[i][j] == row[i] && matrix[i][j] == col[j] ){
                    ans.push_back(matrix[i][j]);
                }
            }

        }
        return ans;        
    }
};