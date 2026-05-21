class Solution {
public:
    int brute(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<int> prefix1;
        for (auto i : arr1) {
            int n = i;
            while (n && prefix1.count(n) == 0) {
                prefix1.insert(n);
                n /= 10;
            }
        }

        for (auto j : arr2) {
            int n = j;
            while (n) {
                if (prefix1.count(n) > 0) {
                    ans = max(ans, n);
                }
                n /= 10;
            }
        }
        int c = 0;
        while (ans) {
            c++;
            ans /= 10;
        }
        return c;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        return brute(arr1, arr2);
    }
};