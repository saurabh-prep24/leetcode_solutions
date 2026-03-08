class Solution {
public:
    // time: O(n * 2^n)
    // space: On)
    string bitMasking(vector<string>& nums) {
        // store unique
        unordered_set<string> unique;
        int n = nums.size();
        // add input str
        for (auto i : nums) {
            unique.insert(i);
        }
        // convert to required format with bitmask
        // this is used to create all sub-seq
        for (int mask = 0; mask < (1 << n); mask++) {
            string s(n, '0');
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    s[i] = '1';
                }
            }
            if (unique.find(s) == unique.end()) {
                return s;
            }
        }
        return "";
    }

    // time: O(2^n)
    // space: O(n)
    void solveRec(vector<string>& nums, unordered_set<string>& unique,
                  string temp, string& ans) {
        // temp reached nums.size()
        // [same as str len in ques otherwise len str should be used]
        if (temp.size() == nums.size()) {
            // check if not present in set
            if (unique.count(temp) == 0) {
                // update ans
                ans = temp;
            }
            // return
            return;
        }
        // call with temp + '0'
        solveRec(nums, unique, temp + '0', ans);
        // any str works so return ans if already updated
        if (ans != "") {
            return;
        }
        // call for temp + '1'
        solveRec(nums, unique, temp + '1', ans);
        return;
    }
    string solveWithDFS(vector<string>& nums) {
        unordered_set<string> unique;
        for (auto i : nums) {
            unique.insert(i);
        }

        string temp = "", ans = "";
        solveRec(nums, unique, temp, ans);
        return ans;
    }

    // time: O(N)
    // space: O(1)
    string solveDiagonalTrick(vector<string>& nums) {
        // for each nums[i]
        // invert nums[i] for each diagonals str
        // since nums.size() is same as len of str
        // we can get unique str with this
        // n = 2
        // 1 1
        // 0 1
        // change nums[0][0] = 0
        // change nums[1][1] = 1
        // ans = 01

        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // return bitMasking(nums);
        // return solveWithDFS(nums);
        return solveDiagonalTrick(nums);
    }
};