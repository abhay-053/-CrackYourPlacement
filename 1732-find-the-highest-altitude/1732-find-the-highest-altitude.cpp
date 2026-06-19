class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;

        int sum = 0;
        for(auto &i: gain){
            sum += i;
            ans = max(ans, sum);
        }
        return ans;
    }
};