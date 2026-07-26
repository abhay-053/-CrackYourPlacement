class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;
        int ans = min(height[i], height[j]) * (j-i);
        while(i < j){
            if(height[i] > height[j]){
                ans = max(ans, height[j] * (j-i));
                j--;
            } else if(height[i] < height[j]){
                ans = max(ans, height[i] * (j-i));
                i++;
            } else {
                ans = max(ans,height[i] * (j-i));
                i++;
                j--;
            }
        }
        return ans;
    }
};