class Solution {
public:
    vector<long long> brute(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    sum += abs(i - j);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }

    vector<long long> opt(vector<int>& nums) {
        unordered_map<int, vector<long long>> posMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            posMap[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        // check to get dist in optimal way
        // LC Problem [1685]
        // https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
        for (auto i : posMap) {
            auto v = i.second;
            int m = v.size();
            vector<long long> prefixSum = v;
            for (int j = 1; j < m; j++) {
                prefixSum[j] += prefixSum[j - 1];
            }
            for (int j = 0; j < m; j++) {
                long long sum = 0;
                if (j > 0)
                    sum += (j * v[j]) - prefixSum[j - 1];
                sum += (prefixSum[m - 1] - prefixSum[j]) - 1LL*((m - 1 - j) * v[j]);
                ans[v[j]] = sum;
            }
        }
        return ans;
    }
    vector<long long> distance(vector<int>& nums) {
        // return brute(nums);
        return opt(nums);
    }
};