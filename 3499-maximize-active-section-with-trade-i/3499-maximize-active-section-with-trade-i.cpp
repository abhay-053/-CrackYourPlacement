class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>> group;
        int n = s.size();
        int cnt = 1;
        for(int i = 1; i< n; i++){
            if(s[i] != s[i-1]){
                group.push_back({s[i-1] - '0', cnt});
                cnt = 0;
            }
            cnt++;
        }
        group.push_back({s[n-1] -'0', cnt});

        cnt = count(begin(s), end(s), '1');

        // for(auto i: group){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int ans = 0;
        int i = 0;
        while( i< group.size() ){
            int curr = 0;

            if(group[i].first == 0){
                if(i + 2 < group.size()){
                    curr = group[i].second + group[i+2].second;
                    curr += cnt;
                }
                i += 2;
            } else {
                i ++;
            }

            ans = max(ans, curr);
        }
        return max(cnt,ans);
    }
};