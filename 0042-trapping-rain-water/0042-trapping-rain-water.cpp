class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int maxl=0, maxr=0;
        int res=0;
        int left=0, right=n-1;
        while(left<=right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= maxl)
                    maxl= height[left];
                else
                    res+= maxl- height[left];
                left++;
            }
            else
            {
                if(height[right]>= maxr)
                    maxr= height[right];
                else
                    res+= maxr- height[right];
                right--;
            }
        }
        return res;
    }
};