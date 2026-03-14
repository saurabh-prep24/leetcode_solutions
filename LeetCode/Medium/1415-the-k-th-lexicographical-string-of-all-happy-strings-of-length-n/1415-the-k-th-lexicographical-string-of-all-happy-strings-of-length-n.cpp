class Solution {
public:
    // allowed chars are [a,b,c]
    char allowed[3] = {'a', 'b', 'c'};

    // build all happy str
    void getAllHappyStr(int n, string curr, vector<string>& arr, char last,
                        int& k) {
        if (curr.size() == n) {
            // push to list of happy arr
            arr.push_back(curr);
            k--;
            return;
        }

        // loop for each allowed chars
        for (auto i : allowed) {
            if (k == 0) {
                return;
            }
            // ensure last != i -> curr[i+1] != curr[i](last)
            if (i != last) {
                getAllHappyStr(n, curr + i, arr, i, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> happyStrs;
        string curr = "";
        int reqIndex = k;
        // populate happy str
        getAllHappyStr(n, curr, happyStrs, ' ', k);
        // sort all strs -> not needed
        // as its being created in sorted order only
        // instead pass k and return once kth index is populated
        // for(auto i: happyStrs){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // sort(happyStrs.begin(), happyStrs.end());
        // for(auto i: happyStrs){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // if k>len then "" else return (k-1)th happy str
        // return k > happyStrs.size() ? "" : happyStrs[k - 1];
        return reqIndex > happyStrs.size() ? "" : happyStrs[happyStrs.size() - 1];
    }
};