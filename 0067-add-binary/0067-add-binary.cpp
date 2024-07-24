class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry=0;
        int n=a.length()-1, m=b.length()-1;
        while( n>=0 || m>=0 )
        {
            int sum=carry;
            if(n>=0)
            {
                sum+= a[n--] - '0';
            }
            if(m>=0)
            {
                sum+= b[m--]-'0';
            }
            carry= sum/2;
            res= to_string(sum%2)+res;
        }
        if(carry)   
            res= to_string(carry)+res;
        return res;
    }
};