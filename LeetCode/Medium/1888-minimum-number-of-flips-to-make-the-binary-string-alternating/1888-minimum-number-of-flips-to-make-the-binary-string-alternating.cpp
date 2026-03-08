class Solution {
public:
    int convert(string temp, int start, int end) {
        int ans = 0, n = end;
        // by comparing with curr and next char
        // invert next if same with curr and update ans
        for (int i = start; i < n - 1; i++) {
            if (temp[i] == temp[i + 1]) {
                temp[i + 1] = !(temp[i] - '0') + '0';
                ans++;
            }
        }
        return ans;
    }

    // Time: O(N*N)
    // Space: O(N)
    int brute(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }
        string temp = s + s;
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            // calc with curr str
            int currAns = convert(temp, i, i + n);
            ans = min(ans, currAns);
        }
        return ans;
    }

    int slidingWindow(string s) {
        // s0 -> s[0] = 0 so 0101....
        // s1 -> s[1] = 0 so 1010....

        // using this we can check for each s[i] and build ans
        // add pattern upto 2n for comparision as rolling wont work for odd
        // 01010 ->
        // pattern -> 01010 + 10101
        // with rolling -> 01010 + 01010 - [X] wrong pattern
        string s0, s1;
        // s = s+s; // for input s we can use rotating cyclic index instead
        int n = s.size();
        for (int i = 0; i < 2 * n; i++) {
            s0 += (i % 2 == 0) ? '0' : '1'; // 0101
            s1 += (i % 2 == 0) ? '1' : '0'; // 1010
        }

        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        int count0 = 0, count1 = 0;
        while (j < 2 * n) {
            // add count
            if (s[j % n] != s0[j]) {
                count0++;
            }

            if (s[j % n] != s1[j]) {
                count1++;
            }
            // shrink window
            if (j - i + 1 > n) {
                // remove excluded char from count
                if (s[i % n] != s0[i]) {
                    count0--;
                }
                // remove excluded char from count
                if (s[i % n] != s1[i]) {
                    count1--;
                }
                // inc left
                i++;
            }

            // update ans
            if (j - i + 1 == n) {
                ans = min({ans, count0, count1});
            }
            // inc right
            j++;
        }
        return ans;
    }

    // PRE_REQ: solve below where only type 2 ops is possible
    // https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description
    int minFlips(string s) {
        // return brute(s);
        return slidingWindow(s);
    }
};