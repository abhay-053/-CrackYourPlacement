class Solution {
public:
    string kthDistinct(vector<string> &v, int k)
    {
        string ans = "";
        unordered_map<string, int> mp;

        for (int i=0;i<v.size(); i++)
        {
            mp[v[i]]++;
        }

        for (int i=0;i<v.size(); i++)
        {
            if(mp[v[i]] == 1)
            {
            k--;
            }
            if(k==0)
            {
            return v[i];
            }
        }
        return "";
    }
};