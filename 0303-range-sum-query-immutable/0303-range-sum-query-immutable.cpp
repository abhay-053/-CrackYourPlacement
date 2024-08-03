class NumArray {
public:
    vector<int> arr;
    vector<int> prefix;
    void prefixsum(vector<int>& arr, int n)
    {
        prefix.resize(n);
        for(int i=0;i<n;i++)
        {
            i==0?prefix[i] = arr[i]:prefix[i] = prefix[i-1]+arr[i];
        }
    }
    NumArray(vector<int>& nums) {
        arr = nums;
        prefixsum(arr,nums.size());
    }
    
    int sumRange(int left, int right) {
        return left-1>=0?prefix[right] - prefix[left-1]:prefix[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */