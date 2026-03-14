class Solution {
public:
    // allowed chars are [a,b,c]
    char allowed[3] = {'a', 'b', 'c'};

    // build all happy str
    // void getAllHappyStr(int n, string curr, vector<string> &arr, char last,
    // int& k) {
    void getAllHappyStr(int n, string &curr, int& k, string &ans) {
        if (curr.size() == n) {
            // push to list of happy arr
            // arr.push_back(curr);

            // cout << curr << endl;
            k--;
            if (k == 0)
                ans = curr;
            return;
        }

        // loop for each allowed chars
        for (auto i : allowed) {
            // ensure last != i -> curr[i+1] != curr[i](last)
            if (curr.size() > 0 && i == curr.back()) {
                continue;
            }
            // getAllHappyStr(n, curr + i, arr, i, k);
            // getAllHappyStr(n, curr + i, k, ans); -> 
            // curr + i -> O(N) space due to new copy
            // using curr.push and pop is O(1)
            curr.push_back(i);
            getAllHappyStr(n, curr, k, ans);
            curr.pop_back();
            if (ans.size() > 0) {
                return;
            }
        }
    }

    // time: O(3 * 2^(n-1)) ~ O(2^n)
    // space: O(n)
    string getHappyString(int n, int k) {
        vector<string> happyStrs;
        string curr = "";
        int reqIndex = k;
        // populate happy str
        // getAllHappyStr(n, curr, happyStrs, ' ', k);
        // OPT:
        // 1. sort all strs -> not needed
        // as its being created in sorted order only
        // sort(happyStrs.begin(), happyStrs.end());

        // 2. instead pass k and return once kth index is populated
        // also we dont need to store all happy str just use ans
        // return when k th str is found
        string ans = "";
        getAllHappyStr(n, curr, k, ans);

        // for(auto i: happyStrs){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // if k>len then "" else return (k-1)th happy str
        // return k > happyStrs.size() ? "" : happyStrs[k - 1];
        // return reqIndex > happyStrs.size() ? "" : happyStrs[happyStrs.size()
        // - 1];
        return ans;
    }
};