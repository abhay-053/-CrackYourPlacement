class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();

        int ele, nse, pse, ans = 0;
        for(int i = 0; i< n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                ele = heights[st.top()];
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();
                ans = max(ans, ele * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty() ){
            ele = heights[st.top()];
            st.pop();

            nse = n;
            pse = st.empty() ? -1 : st.top();
            ans = max(ans, ele * (nse - pse - 1));
        }
    return ans;
    }
};