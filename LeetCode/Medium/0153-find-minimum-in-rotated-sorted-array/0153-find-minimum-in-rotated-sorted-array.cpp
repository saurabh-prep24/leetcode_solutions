class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int i = 0, n = nums.size(), j = n - 1;
        int m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (nums[m] >= nums[i]) {
                mini = min(mini, nums[i]);
                i = m + 1;
            } else {
                mini = min(mini, nums[m]);
                j = m - 1;
            }
        }
        return mini;
    }
};