class Solution {
public:
    // time: O(n^3)
    int brute(vector<int>& nums, int target) {
        int ans = 0;
        int currDiff = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int s = nums[i] + nums[j] + nums[k];
                    if (abs(s - target) < currDiff) {
                        currDiff = abs(s - target);
                        ans = s;
                    }
                }
            }
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        return brute(nums, target);
    }
};