class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int count=0;
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(auto i: edges)
        {
            dp[i[0]][i[1]]= i[2];
            dp[i[1]][i[0]]= i[2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(dp[j][k] > dp[j][i] + dp[i][k])
                    {
                        dp[j][k] = dp[j][i] + dp[i][k];
                    }
                }
            }
        }
        vector<pair<int,int>> ans; 
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            count=0;
            for(int j=0;j<n;j++)
            {
                if( dp[i][j] <= distanceThreshold && i!=j)
                {
                    count++;
                }
            }
            ans.push_back({count,i});
        }
        if(ans.size()==0)
            return -1;
        if(ans.size()==1)
        {
            return ans[0].second;
        }
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\t";
        }
        int flag=0;
        for(int i=0;i<ans.size()-1;i++)
        {
            res.push_back(ans[i].second);
            if(ans[i].first == ans[i+1].first)
            {
                flag=1;
                continue;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            return ans[ans.size()-1].second;
        }
        sort(res.rbegin(),res.rend());
        return res[0];
    }
};