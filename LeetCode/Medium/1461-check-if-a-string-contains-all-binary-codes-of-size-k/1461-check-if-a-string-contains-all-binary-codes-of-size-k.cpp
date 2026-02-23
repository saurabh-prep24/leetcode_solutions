class Solution {
public:
    void getSubSeq(int index, int k, vector<string>& subseq, string curr) {
        if (index == k) {
            subseq.push_back(curr);
            return;
        }

        getSubSeq(index + 1, k, subseq, curr + '0');
        getSubSeq(index + 1, k, subseq, curr + '1');
    }
    bool contains(string& s, string& t) {
        // find t in s - O(N)
        return s.find(t) != string::npos;
    }
    /*
        at each place either 0 or 1
        now for k places - 2^k
        k<=20
        2^20
        2^10 = 1024
        1024 x 1024 < 10^7
        build all sub-seq of k size with 0 or 1 at each places ->
        time: O(2^k) ~ O(10^6)
        space: O(2^k) ~ O(10^6)
        then check if all elem are present into given str - O(n)
        total time: O(n * 10^6) ~ 10^12
        space: O(10^6)
    */
    // time: O(10^6 * N)
    // space: O(10^6)
    bool brute(string s, int k) {
        vector<string> subSeqList;
        getSubSeq(0, k, subSeqList, "");
        for (auto& i : subSeqList) {
            // cout << i << endl;
            if (!contains(s, i)) {
                return 0;
            }
        }
        return 1;
    }

    bool caculatePermutation(string s, int k){
        // for each position there is 2 choices 0 or 1
        // for k size there 2^k options
        // now no of substr of k sizes
        // (n - k + 1) -> ex - n = 5, k = 2 -> substr = 5-2+1 = 4
        // now with this -> total substr >= 2^k [1<<k = 2^k -> rightshift 1 k times]
        // if not possible then return false
        if (s.size() - k + 1 < (1 << k)) {
            return 0;
        }
        // there can be duplicate sub str - 00, 00 etc
        // so put into set to store unique substr
        // now total substr should be >= 2^k
        unordered_set<string> substr;
        for(int i=0;i<s.size()-k+1;i++){
            substr.insert(s.substr(i, k));
        }
        // substr count can't be greater than 2^k as substr are of k len
        return substr.size() == (1<<k);
    }
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) {
            return 0;
        }

        // return brute(s, k);
        return caculatePermutation(s, k);
    }
};
