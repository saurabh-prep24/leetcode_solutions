class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return 0;
        int n = goal.size();
        for (int i = 0; i < n; i++) {
            // matched
            if (s == goal)
                return 1;

            // rotate left by one places
            char st = s[0];
            for (int j = 1; j < n; j++) {
                s[j - 1] = s[j];
            }
            s[n - 1] = st;
        }
        // no match
        return 0;
    }
};