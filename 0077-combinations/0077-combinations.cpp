class Solution {
public:
    void helper(int n, int k , vector<vector<int>>& ans, vector<int>& tmp, int idx )
    {
        if(tmp.size()== k)
        {
            ans.push_back(tmp);
            return ;
        }
        for(int i=idx;i<=n;i++)
        {
            tmp.push_back(i);
            helper(n,k,ans,tmp,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(n,k,ans,tmp,1);
        return ans;
    }
};