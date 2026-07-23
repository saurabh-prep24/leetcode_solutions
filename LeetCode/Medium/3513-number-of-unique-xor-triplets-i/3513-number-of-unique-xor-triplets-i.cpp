class Solution {
public:
    // time: O(n^3)
    // space: O(n)
    int brute(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = j; k < n; k++) {
                    s.insert(nums[i] ^ nums[j] ^ nums[k]);
                }
            }
        }
        return s.size();
    }

    // time: O(log n)
    int opt(vector<int>& nums) {
        // for n = 1 => [1] -> {1}
        // n = 2 => [1,2] -> {1,2}
        // n = 3 {1 1} => [1,2,3] -> {0,1,2,3} [max reached till 3 including 0 = 4]
        // n = 4 {1 0 0} => [1,2,3,4] -> [max reached till 111 = 7 including 0 = 8]
        // [next greater power of 2 greater than n]
        // for any n with xor we can't move above n so upper bound can be all
        // 1's in all binary places of n or do OR of all numbers
        // most significant digit will be power of 2 greater than n
        // or we can just mutiply till we reach >= n [if n>=3]
        // n < 3 return n from observations
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        int a = 1;
        while (a <= n) {
            a *= 2;
        }
        return a;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        // return brute(nums);
        return opt(nums);
    }
};