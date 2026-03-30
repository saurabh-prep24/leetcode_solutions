class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return 0;
        }
        int i = 0;
        for (; i + 2 < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                continue;
            } else if (s1[i + 2] == s2[i]) {
                swap(s1[i], s1[i + 2]);
            } else {
                return 0;
            }
        }
        while (i < s1.size()) {
            if (s1[i] != s2[i]) {
                return 0;
            }
            i++;
        }
        return 1;
    }
};