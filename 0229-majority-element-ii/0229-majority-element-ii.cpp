class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = 0, majority2 = 0;
        int num1 = 0, num2 = 0;
        int n = nums.size();

        for (int x : nums) {
            if (majority1 > 0 && num1 == x) {
                majority1++;
            }
            else if (majority2 > 0 && num2 == x) {
                majority2++;
            }
            else if (majority1 == 0) {
                num1 = x;
                majority1 = 1;
            }
            else if (majority2 == 0) {
                num2 = x;
                majority2 = 1;
            }
            else {
                majority1--;
                majority2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (x == num1)
                cnt1++;
            else if (x == num2)
                cnt2++;
        }

        vector<int> ans;

        if (cnt1 > n / 3)
            ans.push_back(num1);

        if (cnt2 > n / 3)
            ans.push_back(num2);

        return ans;
    }
};