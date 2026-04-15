class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), start = startIndex;
        int ans = INT_MAX;

        // right
        for (int i = 0; i < n; i++) {
            if (words[(i + start) % n] == target) {
                ans = min(ans, abs(i));
            }
        }

        // left
        for (int i = 0; i < n; i++) {
            if (words[(n + start - i) % n] == target) {
                ans = min(ans, abs(i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};