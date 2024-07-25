class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            int id = nums[i]%n;
            nums[id] = nums[id]+n;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            //cout<<nums[i]<<" ";
            int num = i;
            int sub = nums[num]%n;
            if(sub==0) sub = n;
            int freq = (nums[num]-sub)/n;
            if(freq == 2){
                if(i==0) res.push_back(n);
                else res.push_back(num);
            }
        }
        return res;
    }
};