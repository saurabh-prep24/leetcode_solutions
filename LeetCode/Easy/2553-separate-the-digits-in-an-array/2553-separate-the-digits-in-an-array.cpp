class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int curr = nums[i];
            while (curr) {
                ans.push_back(curr % 10);
                curr /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};