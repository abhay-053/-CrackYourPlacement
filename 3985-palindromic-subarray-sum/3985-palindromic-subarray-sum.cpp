class Solution {
public:
    long long getSum(vector<int>& nums) {
        vector<int> tmp;

        tmp.push_back(-1);
        for(auto &val: nums){
            tmp.push_back(0);
            tmp.push_back(val);
        }
        tmp.push_back(0);
        tmp.push_back(-2);

        int n = tmp.size();
        vector<long long> prefix(n-1, 0);
        prefix[0] = 0;
        for(int i = 1; i< n-1; i++){
            prefix[i] = prefix[i-1] + tmp[i];
        }

        // for(auto i: prefix){
        //     cout<<i<<" ";
        // }cout<<endl;
        vector<int> palindromeRange(n, 0);

        //applying manacher's algorithm

        int center = 0, right = 0;
        for(int i = 1; i < n-1; i++){
            
            int mirror = 2 * center - i;
            if( i< right){
                palindromeRange[i] = min(palindromeRange[mirror], right - i);
            }

            while(tmp[i + palindromeRange[i] + 1] == tmp[i - palindromeRange[i] - 1]){
                palindromeRange[i]++;
            }

            if( i + palindromeRange[i] > right){
                right = i + palindromeRange[i];
                center = i;
            }
        }
        //manacher's end

        // for(auto i: palindromeRange){
        //     cout<<i<<" ";
        // }
        long long sum = 0;
        int l, r;
        for(int i = 2; i < n - 2; i ++ ){
            int val = palindromeRange[i];

            l = i - val;
            r = i + val;

            sum = max(sum, l-1 >= 0 ? prefix[r] - prefix[l-1] : prefix[r]);
        }

        return sum;
    }
};