class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                ans[0] = (abs(nums[i]));
            } else
                nums[abs(nums[i]) - 1] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[1] = (i + 1);
                break;
            }
        }
        return ans;
    }
};