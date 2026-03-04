class Solution {
public:
    // time: O(32n)
    // space: O(32)
    int bitOpt1(vector<int>& nums) {
        int n = nums.size();
        // count of set bits
        vector<int> count(32, 0);
        // set count for each nums[i] for each bit
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            for (int k = 0; k < 32; k++) {
                if ((curr >> k) & 1) {
                    count[k]++;
                }
            }
        }

        int ans = 0;
        // build ans using count of bits
        for (int i = 0; i < 32; i++) {
            if (count[i] % 3) {
                ans = ans | (1 << i);
                // cout << (count[i]) << " " << ans << endl;
            }
        }
        return ans;
    }

    // time: O(32n)
    // space: O(32)
    int bitsOpt2(vector<int>& nums) {
        int ans = 0;
        // count set bits for each nums per bit
        for (int i = 0; i < 32; i++) {
            // total set bits for ith bit
            int sumSetBits = 0;
            // add set bits to sum
            for (auto n : nums) {
                sumSetBits += (n >> i) & 1;
            }
            // build ans
            if (sumSetBits % 3 != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }

    int singleNumber(vector<int>& nums) {
        // return bitsOpt1(nums);
        return bitsOpt2(nums);
    }
};