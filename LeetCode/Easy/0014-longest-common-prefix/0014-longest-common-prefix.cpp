class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            // loop on each chars for 1st string
            char curr = strs[0][i];
            // check if this char is present in all strings
            for (int j = 1; j < strs.size(); j++) {
                if (i < strs[j].size() && strs[j][i] == curr) {
                    continue;
                } else {
                    // match not found or size is not valid so return existing
                    // ans
                    return ans;
                }
            }

            // add curr char to ans
            ans += curr;
        }
        // return ans
        return ans;
    }
};