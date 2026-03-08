class Solution {
public:
    // time: O(n * 2^n)
    // space: On)
    string bitMasking(vector<string>& nums) {
        unordered_set<string> unique;
        int n = nums.size();
        for (auto i : nums) {
            unique.insert(i);
        }
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
        // for(auto i:unique){
        //     cout<<i<<endl;
        // }
        return "";
    }

    // time: O(2^n)
    // space: O(n)
    void solveRec(vector<string>& nums, unordered_set<string>& unique,
                  string temp, string& ans) {
        if (temp.size() == nums.size()) {
            if (unique.count(temp) == 0) {
                ans = temp;
            }
            return;
        }

        solveRec(nums, unique, temp + '0', ans);
        solveRec(nums, unique, temp + '1', ans);
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

    
    string findDifferentBinaryString(vector<string>& nums) {
        // return bitMasking(nums);
        return solveWithDFS(nums);
    }
};