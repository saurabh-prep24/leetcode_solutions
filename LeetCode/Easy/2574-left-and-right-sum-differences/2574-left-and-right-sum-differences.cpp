class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> lSums = nums;
        vector<int> rSums = nums;
        for (auto i = 1; i < n; i++) {
            lSums[i] = nums[i] + lSums[i - 1];
        }
        for (auto i = n - 2; i >= 0; i--) {
            rSums[i] = nums[i] + rSums[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(abs(lSums[i] - rSums[i]));
        }
        return ans;
    }
};