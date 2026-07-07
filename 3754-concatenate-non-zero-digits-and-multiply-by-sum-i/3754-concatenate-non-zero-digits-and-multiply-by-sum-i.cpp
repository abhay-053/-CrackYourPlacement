class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        int sum = 0;
        
        string num = to_string(n);
        string s="";
        for(int i = 0; i < num.size() ; i++){
            if(num[i] != '0'){
                s.push_back(num[i]);
                sum += num[i] - '0';
            }
        }

        long long n1 = stoll(s);
        return n1 * 1ll * sum;
    }
};