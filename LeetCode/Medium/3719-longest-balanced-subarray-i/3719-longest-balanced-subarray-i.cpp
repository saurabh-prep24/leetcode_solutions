class Solution {
public:
    // Given N <= 1500 so brute force can work with all sub-arr
    // Store unique odd and even into set for each sub-arr
    // whenever sizes of sets are same then update ans
    // Time: O(N*N)
    // Space: O(N)
    int longestBalanced(vector<int>& nums) {
        // ans and size
        int ans = 0, n = nums.size();
        // keep odd and even into set for unique
        unordered_set<int> odd;
        unordered_set<int> even;
        // loop via all subsets from i = 0 -> n-1
        for (int start = 0; start < n - 1; start++) {
            // clear both sets before each sub arr
            odd.clear();
            even.clear();
            for (int end = start; end < n; end++) {
                if (nums[end] % 2 == 0) {
                    // even
                    even.insert(nums[end]);
                } else {
                    // odd
                    odd.insert(nums[end]);
                }
                if (even.size() == odd.size()) {
                    // update ans when size are equal 
                    // store max len of sub arr [end-start+1]
                    ans = max(ans, end - start + 1);
                }
            }
        }
        // final ans
        return ans;
    }
};