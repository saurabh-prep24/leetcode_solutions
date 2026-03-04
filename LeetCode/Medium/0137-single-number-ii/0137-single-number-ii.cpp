class Solution {
public:
    // time: O(32n)
    // space: O(32) ~ O(1)
    int bitsOpt1(vector<int>& nums) {
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
    // space: O(32) ~ O(1)
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

    // time: O(n * logn)
    // space: O(n) // copy of nums
    int sortSolve(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (int i = 0; i + 2 < temp.size(); i += 3) {
            if (temp[i] != temp[i + 1]) {
                return temp[i];
            }
        }
        return temp[temp.size() - 1];
    }

    // time: O(n)
    // space: O(n)
    int hashSolve(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        for (auto i : count) {
            if (i.second==1) {
                return i.first;
            }
        }
        return 0;
    }

    int singleNumber(vector<int>& nums) {
        // return sortSolve(nums);
        // return hashSolve(nums);
        // return bitsOpt1(nums);
        return bitsOpt2(nums);
    }
};