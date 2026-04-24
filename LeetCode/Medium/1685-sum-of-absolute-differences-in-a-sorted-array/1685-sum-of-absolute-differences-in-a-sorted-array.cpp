class Solution {
public:
    // time: O(n*n)
    vector<int> brute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += abs(nums[i] - nums[j]);
            }
            ans.push_back(s);
        }
        return ans;
    }

    // time: O(n)
    // using prefix sum to get sum before and after curr elem
    // [1 2 3  4  5  6]
    // [1 3 6 10 15 21] - prefix
    // for each index -
    // rihgtSum = prefix[last] - prefix[curr] - (nums[curr]*r)
    // [r no. of elem in right]
    // leftSum = (nums[curr]*l) - prefix[curr-1]
    // [l no. of elem in left]
    vector<int> prefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> prefix = nums;
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int s = abs((prefix[n - 1] - prefix[i]) - nums[i] * (n - i - 1));
            if (i > 0) {
                s += abs(nums[i] * i - prefix[i - 1]);
            }
            ans.push_back(s);
        }
        return ans;
    }

    // use prefix and sufix sum arr to get sum in left and right
    vector<int> prefixSufixSum(vector<int>& nums) {
        vector<int> prefixSum = nums;
        vector<int> sufixSum = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i - 1];
            sufixSum[n - i - 1] += sufixSum[n - i];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int leftSum = nums[i] * i - (prefixSum[i] - nums[i]);
            int rightSum = sufixSum[i] - nums[i] - nums[i] * (n - 1 - i);
            ans[i] = (leftSum + rightSum);
        }
        return ans;
    }

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // return brute(nums);
        // return prefixSufixSum(nums);
        return prefixSum(nums);
    }
};