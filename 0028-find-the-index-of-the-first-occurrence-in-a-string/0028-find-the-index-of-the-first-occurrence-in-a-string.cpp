class Solution {
public:
    int strStr(string haystack, string needle) {
        int count=0;
        for(int i=0;i<haystack.size();i++)
        {
            count=0;
            for(int j=0;j<needle.size();j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    break;
                }
                else
                {
                    count++;
                }
            }
            if(count==needle.size())
            {
                return i;
            }
        }
        return -1;
    }
};