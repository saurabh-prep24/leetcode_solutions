class Solution {
public:
    /*
        approach 1:
        use hashmap for counts of nums
        then extract from map with count == 1
        return sorted arr as ans
        time: O(N)
        space: O(N)
    */

    /*
        approach 2:
        divide nums into 2 buckets where LSB are different for these pairs
        doing XOR all elem will result in a^b [both are ans]
        we are sure that they are different so at least 1 bit should be
       different in them else xor will be 0 using this info we can create 2
       buckets where LSB of a are same with other pairs and LSB of b are
       matching with other since other all elem are in pair so doing xor in each
       bucket will give ans for different elem occuring only once for getting
       LSB do -> n&(n-1) ^ n [only LSB is set] then do xor with all elem and
       divide into buckets doing xor among them final will ans in both bucket
        time: O(N)
        space: O(1)
    */
    vector<int> optBinary(vector<int>& nums) {
        long r = 0; // for INT_MIN -> lsb will fail as r-1 will overflow so use long
        for (auto i : nums) {
            r = r ^ i;
        }

        int lsb = (r & (r - 1)) ^ r; // only 1 LSB is set now
        int buc1 = 0;                // nums with lsb same LSB of num
        int buc2 = 0;
        for (auto i : nums) {
            if (i & lsb) {
                buc1 = buc1 ^ i;
            } else {
                buc2 = buc2 ^ i;
            }
        }

        vector<int> ans;
        ans.push_back(buc1);
        ans.push_back(buc2);
        sort(ans.begin(), ans.end());
        return ans;
    }

    vector<int> singleNumber(vector<int>& nums) {
        // binary opt
        return optBinary(nums);
    }
};