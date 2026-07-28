class Solution {
public:
    // time: O(n)
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }

    // time: O(n)
    void getPermutation(string& s, int curr, string& ans) {
        if (curr >= s.size()) {
            if (isPalindrome(s) && ans == "") {
                cout << s << endl;
                ans = s;
            }
            return;
        }
        if (ans != "") {
            return;
        }
        for (int i = curr; i < s.size(); i++) {
            swap(s[i], s[curr]);
            getPermutation(s, curr + 1, ans);
            swap(s[i], s[curr]);
        }
    }
    // time: O(nlogn + n*n!)
    string brute(string& s) {
        sort(s.begin(), s.end());
        string t = "";
        getPermutation(s, 0, t);
        return t;
    }

    // time: O(n)
    // space: O(n)
    string optPart(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        string left = "";
        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] && count[i] % 2 != 0) {
                mid += (i + 'a');
            }
            if (count[i] / 2) {
                int t = 0;
                while (t < count[i] / 2) {
                    left += (i + 'a');
                    t++;
                }
            }
        }
        string final = left;
        final += (mid != "") ? mid : "";
        reverse(left.begin(), left.end());
        final += left;
        return final;
    }
    string smallestPalindrome(string s) {
        // return brute(s);
        return optPart(s);
    }
};