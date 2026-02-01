class Solution {
public:
    bool strCopy(string s) {
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
        string t = s + s;
        t = t.substr(1, t.size() - 2);
        cout << t << " " << s << endl;
        return t.find(s) != string::npos;
    }
    bool bruteForceSubStrMatch(string s) {
        // approach2 : brute force
        // get all sub possible till n/2
        // check if remaining string only contains curr substr
        // Time: O(n*n)
        // space: O(n)
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
    bool match(string& s, int l, int n) {
        if (l >= n) {
            return 0;
        }
        for (int i = l; i < n; i++) {
            if (s[i] != s[i % l]) {
                return 0;
            }
        }
        return 1;
    }
    bool bruteForceOpt(string s) {
        // approach3: brute force with opt
        // as substr creates copy into new str
        // so we can directly use index rather than creating new sub str each
        // time for i>l compare (i%l)[base substr index] with l[curr substr
        // index] and along with this instead of checking l upto n/2
        // we can check upto sqrt(n) and call to match for l and n/l for l>1
        // so time will be n*sqrt(n) with no additional space usage
        // Time: O(N * sqrt(N))
        // Space: O(1)
        int n = s.size();
        // move l upto l < sqrt(n) and check for l and n/l part simulataneously
        for (int l = 1; l * l <= n; l++) {
            // if there are remaining elem with curr substr len then skip
            if (n % l != 0)
                continue;

            // consider match for l or (n/l if l>1 - counter remaining part)
            // "abaababaab"
            // n=10, sqrt(n) = 3
            // l = 1 -> not matched
            // l = 2 -> with 2 len not matched
            // l = 10/2 = 5 -> with 5 len matched
            bool isFound = match(s, l, n) || (l > 1 && match(s, n / l, n));

            // moved to match func
            // for (int i = l; i < n; i++) {
            //     // if s[i] (curr) != s[i%l] (base substr)
            //     if (s[i] != s[i % l]) {
            //         isFound = 0;
            //         break;
            //     }
            // }
            // if match found with curr len then return 1
            if (isFound) {
                return 1;
            }
        }
        // return 0 as no match found
        return 0;
    }

    bool matchWithLPS(string s) {
        int n = s.size();      // size
        vector<int> lps(n, 0); // lps arr
        int len = 0;           // len of lps
        int i = 1;             // curr
        while (i < n) {
            if (s[len] == s[i]) { // match
                len++;
                lps[i] = len; // increment lps val
                i++;          // move ahead
            } else {
                if (len > 0) {
                    // use prev lps val - lps[len-1)
                    len = lps[len - 1];
                    // NOTE: dont move i ahead iteration will compare
                } else {
                    // set lps as 0 and move ahead
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int lastLPS = lps[n - 1];
        int patternLen = n - lastLPS;
        // ex - ababab -> lps [0,0,1,2,3,4]
        // pattern len can be 6-4 = 2
        // check if n % pattenLen == 0
        // so there is no extra char other than pattern
        // if len = 0 then means no pattern exists
        return len > 0 && n % patternLen == 0;
    }

    bool repeatedSubstringPattern(string s) {
        // return strCopy(s);
        // return bruteForceSubStrMatch(s);
        // return bruteForceOpt(s);
        return matchWithLPS(s);
    }
};