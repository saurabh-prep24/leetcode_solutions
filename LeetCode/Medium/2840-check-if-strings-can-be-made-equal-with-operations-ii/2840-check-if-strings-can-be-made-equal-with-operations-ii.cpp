class Solution {
public:
    // time: O(n log n)
    // space: O(n)
    bool brute(string s1, string s2) {
        // store even char of both
        string even1 = "", even2 = "";
        // store odd char of both
        string odd1 = "", odd2 = "";

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even1 += s1[i];
                even2 += s2[i];
            } else {
                odd1 += s1[i];
                odd2 += s2[i];
            }
        }

        // sort all str for both
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        // even str and odd str should be same after sorting
        return (even1 == even2) && (odd1 == odd2);
    }

    // time: O(n)
    // space: O(1)
    bool spaceOpt(string s1, string s2) {
        // keep count of each char at even and odd places
        int countEven[26] = {0};
        int countOdd[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            // cancel out count from s1 and s2
            if (i % 2 == 0) {
                countEven[s1[i] - 'a']++;
                countEven[s2[i] - 'a']--;
            } else {
                countOdd[s1[i] - 'a']++;
                countOdd[s2[i] - 'a']--;
            }
        }

        // check if any count != 0 then str cant be same
        for (int i = 0; i < 26; i++) {
            if (countEven[i] != 0 || countOdd[i] != 0) {
                return 0;
            }
        }
        // return 1 as str can be same
        return 1;
    }
    bool checkStrings(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return 0;
        }
        // return brute(s1, s2);
        return spaceOpt(s1, s2);
    }
};