class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // approach1 : trick using copy of s and using find s on s+s
        // use t = s+s
        // remove first and last char from t
        // if s still exists into t
        // then return 1
        // ex - s = abab | t = abababab
        // t' = bababa contain 'abab' (s)
        // Time: O(n*n)
        // time complexity of std::string::find in C++ is
        // O(n × m) in the worst case
        // Space: O(n)
        // string t = s + s;
        // t = t.substr(1, t.size() - 2);
        // cout << t << " " << s << endl;
        // return t.find(s) != string::npos;

        // approach2 : brute force
        // get all sub possible till n/2
        // check if remaining string only contains curr substr
        int n = s.size();
        for (int l = 1; l <= n / 2; l++) {
            // if there are remaining elem with curr substr len then skip
            if (n % l != 0)
                continue;

            // consider match
            bool isFound = 1;
            // base substr for comp
            string baseSubStr = s.substr(0, l);
            for (int i = l; i < n; i += l) {
                // curr substr to be compared with base substr
                string currSubStr = s.substr(i, l);
                // if not same then break and continue with next len
                if (baseSubStr != currSubStr) {
                    isFound = 0;
                    break;
                }
            }
            // if match found with curr len then return 1
            if (isFound) {
                return 1;
            }
        }
        // return 0 as no match found
        return 0;
    }
};