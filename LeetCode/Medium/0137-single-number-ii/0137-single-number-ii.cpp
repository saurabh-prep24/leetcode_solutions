class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
};