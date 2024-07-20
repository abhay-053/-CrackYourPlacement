#include <iostream>
#include <stack>
#include <string>
#include <cstdlib> // for atoi

using namespace std;

class Solution {
public:
    string decodeString(string s) 
    {
        stack<char> st;
        for(auto i: s)
        {
            if(i != ']')
            {
                st.push(i);
            }
            else
            {
                string str = "";
                
                while(!st.empty() && st.top() != '[')
                {
                    str = st.top() + str;
                    st.pop();
                }
                
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                
                string str2 = "";

                while(!st.empty() && isdigit(st.top()))
                {
                    str2 = st.top() + str2;
                    st.pop();
                }
                
                int num = atoi(str2.c_str());
                
                string repeatedStr = "";
                for(int j = 0; j < num; j++)
                {
                    repeatedStr += str;
                }
                for(char ch : repeatedStr)
                {
                    st.push(ch);
                }
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
