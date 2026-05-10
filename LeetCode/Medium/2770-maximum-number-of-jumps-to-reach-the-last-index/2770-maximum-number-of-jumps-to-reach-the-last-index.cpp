class Solution {
public:
    int rec(vector<int>& nums, int target, int i) {
        int n = nums.size();
        if (i == n - 1) {
            return 0;
        }
        int ans = -1;
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[i] - nums[j]) <= target) {
                int t = rec(nums, target, j);
                if (t != -1)
                    ans = max(ans, 1 + t);
            }
        }
        return ans;
    }

    int recMemo(vector<int>& nums, int target, int i, vector<int>& dp) {
        int n = nums.size();
        if (i == n - 1) {
            return 0;
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }
        int ans = -1;
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[i] - nums[j]) <= target) {
                int t = recMemo(nums, target, j, dp);
                if (t != -1)
                    ans = max(ans, 1 + t);
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // int ans = rec(nums, target, 0);
        // return ans > 0 ? ans : -1;

        vector<int> dp(n + 1, INT_MIN);
        int ans = recMemo(nums, target, 0, dp);
        return ans != INT_MIN ? ans : -1;

        // choice is there at each index to either take or not
        // ex- [1 0 2]
        // if we take 0->1 index then ans = -1
        // if we take 0->2 index then ans = 1
        // so use recursion with knapsack approach
        // int i = 0;
        // int j = 1;
        // int ans = 0;
        // while (j < n) {
        //     if (abs(nums[i] - nums[j]) <= target) {
        //         i = j;
        //         ans++;
        //     }
        //     j++;
        // }
        // if (i != n - 1) {
        //     ans = -1;
        // }
        // return ans;
    }
};