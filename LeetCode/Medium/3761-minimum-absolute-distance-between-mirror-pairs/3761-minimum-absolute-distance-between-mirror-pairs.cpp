class Solution {
public:
    int rev(int n) {
        int rev = 0;
        while (n) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    // time: O(n*n)
    // space: O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int curr = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == rev(curr)) {
                    ans = min(ans, abs(i - j));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    int binarySearch(vector<int>& v, int key) {
        int s = 0, e = v.size() - 1, ans = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            // get ans as first greater then key
            if (v[m] > key) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }

    // time: O(n * logn) [using binary search for index pairs]
    // space: O(n)
    int opt(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        unordered_map<int, vector<int>> places;
        for (int i = 0; i < n; i++) {
            places[nums[i]].push_back(i);
        }

        for (int i = 0; i < n - 1; i++) {
            int curr = rev(nums[i]);
            if (places.count(curr) > 0) {
                vector<int>& t = places[curr];

                // calc upper bound - O(log n)
                int upperBound = binarySearch(t, i);
                if (upperBound != -1) {
                    // cout << i << " " << curr << " " << t[upperBound] << endl;
                    ans = min(ans, abs(t[upperBound] - i));
                }

                // loop for to find 1st t[j] > i - O(n)
                // for (int j = 0; j < t.size(); j++) {
                //     // cout << t[j] << " " << i << " " << nums[i] << " " <<
                //     curr
                //     //      << " " << ans << endl;

                //     // skip cases where rev is same as nums[i]
                //     // occuring before i as i<j is needed
                //     if (t[j] <= i) {
                //         continue;
                //     } else {
                //         ans = min(ans, abs(t[j] - i));
                //         break;
                //     }
                // }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        // return brute(nums);
        return opt(nums);
    }
};