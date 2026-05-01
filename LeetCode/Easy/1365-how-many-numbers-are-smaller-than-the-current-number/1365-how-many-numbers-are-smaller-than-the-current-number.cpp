class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // simple - 2 for loop
        // time: O(n*n)
        // first iterat for each elem
        // second count all arr[j] < arr[i]

        // use hashing in sorted arr
        // after sorting for each elem all left elem (<i) are smaller
        // it indicates count of smaller elem now
        // dont overwrite as there is no equal comparision
        // time: O(N*logN)
        // space: O(N)
        int n = nums.size();
        vector<int> ans;
        // sorting copy of arr
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        // use map to store index for each elem
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = i;
            }
        }

        // for each elem index is count of smaller elem
        // ex: [1 2 3 4 5]
        //     [0 1 2 3 4] - index = count of smaller elems
        for (auto i : nums) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};