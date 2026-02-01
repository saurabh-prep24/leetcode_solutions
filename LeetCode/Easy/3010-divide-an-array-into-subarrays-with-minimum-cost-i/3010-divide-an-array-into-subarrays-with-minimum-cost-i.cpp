class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        int second = INT_MAX, third = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] < second && nums[i] < third) {
                third = second;
                second = nums[i];
            } else if (nums[i] < third) {
                third = nums[i];
            }
        }
        return ans + second + third;
    }
};