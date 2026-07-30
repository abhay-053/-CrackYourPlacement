class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int s_row = startPos[0], s_col = startPos[1];
        int d_row = homePos[0] , d_col = homePos[1];
        int cost= 0;

        //find row cost
        if(s_row > d_row){
            for(int i = s_row - 1; i>= d_row; i--){
                cost += rowCosts[i];
            }
        } else {
            for(int i = s_row + 1; i<= d_row; i++){
                cost += rowCosts[i];
            }
        }

        //find coloumn cost
        if(s_col > d_col){
            for(int j = s_col - 1; j >= d_col ; j--){
                cost += colCosts[j];
            }
        } else {
            for(int j = s_col + 1; j <= d_col ; j++){
                cost += colCosts[j];
            }
        }

        return cost;
    }
};