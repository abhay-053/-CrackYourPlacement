class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int left=0, right= n-1;
        int ans=0, res=0;
        while(left<right)
        {
            int m= min(height[left],height[right]);
            int h= right-left;
            ans = h*m;
            res=max(ans,res);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};







