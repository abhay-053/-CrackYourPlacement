class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            unordered_map<int,int> freq, freqOfFreq;
            for(int j = i; j< n; j++){
                
                int oldFreq = freq[nums[j]];

                freq[nums[j]]++;
                int val = freq[nums[j]];

                if(freqOfFreq.find(oldFreq) != freqOfFreq.end()){
                    freqOfFreq[oldFreq] --;
                    if(freqOfFreq[oldFreq] == 0){
                        freqOfFreq.erase(oldFreq);
                    }
                }

                freqOfFreq[val]++;

                if(freq.size() == 1){
                    ans = max(ans, j-i+1);
                } else if(freqOfFreq.size() ==2 ){
                    int val1 = -1, val2 = -1;
                    for(auto i: freqOfFreq){
                        if(val1 == -1){
                            val1 = i.first;
                        } else {
                            val2 = i.first;
                        }
                    }

                    if(val1 * 2 == val2){
                        ans = max(ans, j-i+1);
                    } else if(val2 * 2 == val1){
                        ans = max(ans, j-i+1);
                    }
                } 
            }
        }
        return ans;
    }
};