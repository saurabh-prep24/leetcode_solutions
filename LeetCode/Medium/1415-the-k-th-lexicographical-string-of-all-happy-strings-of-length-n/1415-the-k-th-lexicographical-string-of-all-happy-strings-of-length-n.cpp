class Solution {
public:
    // allowed chars are [a,b,c]
    char allowed[3] = {'a', 'b', 'c'};

    // build all happy str
    void getAllHappyStr(int n, string curr, vector<string>& arr, char last) {
        if (curr.size() == n) {
            // push to list of happy arr
            arr.push_back(curr);
            return;
        }

        // loop for each allowed chars
        for (auto i : allowed) {
            // ensure last != i -> curr[i+1] != curr[i](last)
            if (i != last) {
                getAllHappyStr(n, curr + i, arr, i);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> happyStrs;
        string curr = "";
        // populate happy str
        getAllHappyStr(n, curr, happyStrs, ' ');
        // sort all strs
        sort(happyStrs.begin(), happyStrs.end());
        // if k>len then "" else return (k-1)th happy str
        return k > happyStrs.size() ? "" : happyStrs[k - 1];
    }
};