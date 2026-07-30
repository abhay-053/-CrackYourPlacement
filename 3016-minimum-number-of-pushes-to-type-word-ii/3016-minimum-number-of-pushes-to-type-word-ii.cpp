class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> freq(26, 0);
        
        for(auto ch: word){
            freq[ch -'a']++;
        }
        sort(rbegin(freq), rend(freq));

        const int val = 8;

        int sum1 = accumulate(begin(freq), begin(freq)+val, 0);
        int sum2 = accumulate(begin(freq)+val, begin(freq)+(2*val), 0);
        int sum3 = accumulate(begin(freq)+(2*val), begin(freq)+(3*val), 0);
        int sum4 = freq[24] + freq[25];


        ans = sum1 + (2 * sum2) + (3 * sum3) + (4 * sum4);
        return ans;
    }
};