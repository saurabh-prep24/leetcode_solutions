class Solution {
public:
    int rec(vector<int>& nums, int target, int i) {
        int n = nums.size();
        // final dest
        if (i == n - 1) {
            return 0;
        }
        // start ans = -1
        int ans = -1;
        for (int j = i + 1; j < n; j++) {
            // check all valid j and call for rec
            if (abs(nums[i] - nums[j]) <= target) {
                int t = rec(nums, target, j);
                // if valid then update ans
                if (t != -1)
                    // consider current jump so 1+t
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

    int tab(vector<int>& nums, int target) {
        int n = nums.size();
        // dp tab
        vector<int> dp(n + 1, -1);
        // last index jump = 0
        dp[n - 1] = 0;
        // explore reverse of recMemo
        for (int i = n - 2; i >= 0; i--) {
            int ans = -1;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    // check already solved dp[j]
                    int t = dp[j];
                    if (t != -1)
                        ans = max(ans, 1 + t);
                }
            }
            // store curr ans
            dp[i] = ans;
        }
        // final ans
        return dp[0];
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // int ans = rec(nums, target, 0);
        // return ans > 0 ? ans : -1;

        // vector<int> dp(n + 1, INT_MIN);
        // return recMemo(nums, target, 0, dp);

        return tab(nums, target);

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