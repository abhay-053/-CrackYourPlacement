class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size() == 0){
            return n-1;
        }
        restrictions.push_back({1,0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());

        int sz = restrictions.size();
        
        int start = 0;
        int end;
        for(int i = 1; i < sz ; i++) {
            restrictions[i][1] = min(start  + restrictions[i][0] - restrictions[i-1][0], restrictions[i][1]);
            start = restrictions[i][1];
        }
        
        start = restrictions[sz - 1][1];
        for(int i = sz - 2; i>= 2; i--){
            restrictions[i][1] = min(restrictions[i][1], start + restrictions[i+1][0] - restrictions[i][0] );
            start = restrictions[i][1];
        }
        // for(auto &i: restrictions ){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }

        //(m-start) + (m - end) <= d -> (j - i)
        int ans = 0;
    
        for(int i = 1; i< sz; i++){
            int d = restrictions[i][0] - restrictions[i-1][0];
            start = restrictions[i-1][1];
            end = restrictions[i][1];

            int m = (d + start + end) / 2;
            ans = max(m, ans);
        }
        return ans;
    }
};