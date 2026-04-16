class Solution {
public:
    int nearest(vector<int>& nums, int start, int target) {
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[(start + i) % n] == target) {
                return i;
            }
            if (nums[(n + start - i) % n] == target) {
                return i;
            }
        }
        return -1;
    }
    // time: O(n*n)
    // space: O(n)
    vector<int> brute(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int target = nums[queries[i]];
            int start = queries[i];
            int t = nearest(nums, start, target);
            ans.push_back(t);
        }
        return ans;
    }

    int findClose(vector<int>& pos, int start, int n) {
        int l = 0, r = pos.size() - 1;
        int idx = pos.size();

        // manual lower_bound
        while (l <= r) {
            int m = (l + r) / 2;
            if (pos[m] >= start) {
                idx = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        int k = pos.size();

        // right candidate
        int right = (idx == k ? 0 : idx);
        if (pos[right] == start) {
            right = (right + 1) % k; // skip self
        }

        // left candidate
        int left = (idx == 0 ? k - 1 : idx - 1);
        if (pos[left] == start) {
            left = (left - 1 + k) % k; // skip self
        }

        int d1 = abs(pos[right] - start);
        int d2 = abs(pos[left] - start);

        d1 = min(d1, n - d1);
        d2 = min(d2, n - d2);

        return min(d1, d2);
    }
    vector<int> opt(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> places;
        for (int i = 0; i < nums.size(); i++) {
            places[nums[i]].push_back(i);
        }

        int n = nums.size(), m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int target = nums[queries[i]];
            int start = queries[i];
            vector<int>& curr = places[target];
            if (curr.size() > 1) {
                ans.push_back(findClose(curr, start, n));
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // return brute(nums, queries);
        return opt(nums, queries);
    }
};