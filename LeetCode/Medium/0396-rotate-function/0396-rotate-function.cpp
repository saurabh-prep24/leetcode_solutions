class Solution {
public:
    // time: O(n)
    int getF(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += i * nums[i];
        }
        return ans;
    }

    // time: O(n)
    void rotateClockwise(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
    }

    // time: O(n)
    void rotateClockwiseWithF(vector<int>& nums, int& ans) {
        int n = nums.size(), t = 0;
        int last = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
            t += i * nums[i];
        }
        nums[0] = last;
        ans = max(ans, t);
    }

    /*
        a = [a b c d] f(0) = a*0+b*1+c*2+d*3
        a1 =[d a b c] f(1) = d*0+a*1+b*2+c*3
        f(1) - f(0) = a(1-0)+b(2-1)+c(3-2)+d(0-3) = a+b+c-3d = a+b+c+d-4d
        f(k) = sum(arr)-len(arr)*(arr[n-k]) + f(k-1)
        dp[i] = dp[i-1] + sum(arr) - n * arr[n-i]
    */
    // time: O(n)
    // space: O(n)
    int solveMath(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            dp[0] += i * nums[i];
        }
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + sum - n * nums[n - i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // time: O(n)
    // space: O(1) - remove dp arr
    int solveMathOpt(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prev += i * nums[i];
        }
        int ans = prev;
        for (int i = 1; i < n; i++) {
            int next = prev + sum - n * nums[n - i];
            ans = max(ans, next);
            prev = next;
        }
        return ans;
    }
    int maxRotateFunction(vector<int>& nums) {
        // int ans = INT_MIN, n = nums.size();
        // time: O(n*n) => TLE
        // for (int i = 0; i < n; i++) {
        //     // ans = max(ans, getF(nums));
        //     // cout << nums[0] << " " << endl;
        //     // rotateClockwise(nums);

        //     // rotateClockwiseWithF(nums, ans);
        // }
        // return ans;

        // return solveMath(nums);
        return solveMathOpt(nums);
    }
};