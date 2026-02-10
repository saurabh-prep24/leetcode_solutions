class Solution {
public:
    // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    // find largest index k from last such that a[k] < a[k+1]
    // find largest index l such that a[k] < a[l]
    // swap a[k] and a[l]
    // sort from i = k+1 to last elem
    // [1,2,3,4]
    // k = 2 as a[2] < a[3] [largest k]
    // l = 3 as a[k] < a[l] => a[2]<a[3] => l = 3
    // swap a[2] , a[3] => [1,2,4,3]
    // sort from k+1 to n [nothing as remaining is last elem]
    vector<int> solveAlgo(vector<int>& v) {
        int n = v.size();
        int k = -1, l = 0;
        // get k index where a[k] < a[k+1]
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                k = i;
                break;
            }
        }
        // cout<<k<<endl;
        if (k == -1) {
            // if no k is found then given is last permutation
            // we can sort and return to get first one
            sort(v.begin(), v.end());
            return v;
        }

        // get l index where a[k] < a[l]
        for (int i = k + 1; i < n; i++) {
            if (v[k] < v[i]) {
                l = i;
            }
        }
        // swap
        swap(v[k], v[l]);
        // sort from k+1 to n
        sort(v.begin() + k + 1, v.end());
        // return
        return v;
    }

    vector<int> brute(vector<int> &v){
        // store copy of v
        // sort v
        // get all permutations
        // sort them
        // comapare with copy
        // return next permutations
        return {};
    }
    void nextPermutation(vector<int>& nums) { nums = solveAlgo(nums); }
};