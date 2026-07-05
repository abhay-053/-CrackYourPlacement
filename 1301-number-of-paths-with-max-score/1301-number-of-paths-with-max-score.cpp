class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<long long>> arr(n, vector<long long>(m, 0));
        int i = 0; 
        int j = 0;
        for(auto str: board){
            j = 0;
            for(auto ch: str){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    arr[i][j] = board[i][j]- '0';
                } else if(board[i][j] == 'X'){
                    arr[i][j] = -1;
                }
                j++;
            }
            i++;
        }


        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long ,long long>>(m));
        dp[n-1][m-1] = {0, 1};
        for(int j = m - 2; j>=0; j--){
            if(arr[n-1][j] == -1){
                break;
            }
            dp[n-1][j] = { dp[n-1][j+1].first + arr[n-1][j], 1};
        }

        for(int i = n - 2; i>=0; i--){
            if(arr[i][m-1] == -1){
                break;
            }
            dp[i][m-1] = { dp[i+1][m-1].first + arr[i][m-1], 1};
        }

        for(int i = n-2; i>=0; i--){
            for(int j = m-2; j>=0 ;j--){
                if(arr[i][j] == -1 ){
                    continue;
                }

                if(dp[i+1][j].first > dp[i+1][j+1].first){
                    if(dp[i+1][j].first > dp[i][j+1].first){
                        dp[i][j].first = dp[i+1][j].first + arr[i][j];
                        dp[i][j].second = dp[i+1][j].second;
                    } else if(dp[i+1][j].first < dp[i][j+1].first ){
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = dp[i][j+1].second;
                    } else {
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = (dp[i][j+1].second + dp[i+1][j].second) % MOD;
                    }
                    
                } else if(dp[i+1][j].first > dp[i+1][j+1].first) {
                    if(dp[i+1][j+1].first > dp[i][j+1].first){
                        dp[i][j].first = dp[i+1][j+1].first + arr[i][j];
                        dp[i][j].second = dp[i+1][j+1].second;
                    } else if(dp[i+1][j+1].first < dp[i][j+1].first ){
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = dp[i][j+1].second;
                    } else {
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = (dp[i+1][j+1].second + dp[i+1][j].second) % MOD;
                    }
                } else {
                    if(dp[i+1][j+1].first > dp[i][j+1].first){
                        dp[i][j].first = dp[i+1][j+1].first + arr[i][j];
                        dp[i][j].second = (dp[i+1][j+1].second + dp[i+1][j].second) % MOD;
                    } else if(dp[i+1][j+1].first < dp[i][j+1].first ){
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = dp[i][j+1].second;
                    } else {
                        dp[i][j].first = dp[i][j+1].first + arr[i][j];
                        dp[i][j].second = ( (dp[i][j+1].second + dp[i+1][j+1].second) % MOD + dp[i+1][j].second) % MOD;
                    }
                }
            }
        }

        
        long long a = dp[0][0].first;
        long long b = dp[0][0].second;
        cout<<a<<" "<<b<<endl;
        if(b== 0){
            return {0,0};
        }

        a %= MOD;
        b %= MOD;
        
        return {(int)a, (int)b};
    }
};