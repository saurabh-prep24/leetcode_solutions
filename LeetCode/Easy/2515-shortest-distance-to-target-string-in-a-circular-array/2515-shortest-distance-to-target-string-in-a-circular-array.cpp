class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            // right - (i+startIndex)%n
            if (words[(i + startIndex) % n] == target) {
                return i;
            }
            // left - (n+startIndex-i)%n
            if (words[(n + startIndex - i) % n] == target) {
                return i;
            }
        }

        return -1;
    }
};