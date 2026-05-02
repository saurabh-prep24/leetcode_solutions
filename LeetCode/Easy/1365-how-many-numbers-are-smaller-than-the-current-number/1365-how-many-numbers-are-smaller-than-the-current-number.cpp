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
        // int n = nums.size();
        // vector<int> ans;
        // // sorting copy of arr
        // vector<int> temp = nums;
        // sort(temp.begin(), temp.end());

        // // use map to store index for each elem
        // unordered_map<int, int> mp;
        // for (int i = 0; i < n; i++) {
        //     if (mp.find(temp[i]) == mp.end()) {
        //         mp[temp[i]] = i;
        //     }
        // }

        // // for each elem index is count of smaller elem
        // // ex: [1 2 3 4 5]
        // //     [0 1 2 3 4] - index = count of smaller elems
        // for (auto i : nums) {
        //     ans.push_back(mp[i]);
        // }
        // return ans;


        // as n <= 100
        // using count bucket and then cumulative sums
        // we can get ans
        // ex. arr :    [8,1,2,2,3]
        //  counts :    [0,1,2,1,0,0,0,1]
        //  cumCount:   [0,1,3,4,4,4,4,5]
        //  ans :       [4,0,1,1,3]
        int counts[101] = {0};
        for (auto i : nums) {
            counts[i]++;
        }

        for (int i = 1; i < 101; i++) {
            counts[i] += counts[i - 1];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0){
                ans.push_back(0);
            }else
                ans.push_back(counts[nums[i] - 1]);
        }
        return ans;
    }
};