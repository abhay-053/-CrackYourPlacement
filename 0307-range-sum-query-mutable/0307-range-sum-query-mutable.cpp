class NumArray {
public:
    vector<int> BIT;
    vector<int> nums;
    int n;
    NumArray(vector<int>& arr) {
        n = arr.size();
        BIT.resize(n+1, 0);
        nums = arr;
        for(int i = 1; i <= n; i++){
            add(i, nums[i-1]);
        }
    }
    
    void add(int idx, int val){
        while(idx <= n){
            BIT[idx] += val;

            idx += idx & (-idx);
        }
    }
    void update(int index, int val) {
        add(index + 1, -nums[index]);
        nums[index] = val;
        add(index + 1, val);
    }
    
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */