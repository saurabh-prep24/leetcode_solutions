class Solution {
public:
    // using sliding window technique
    // capture len of continous 1s and keeping maxi as max len 
    // if there is any 0 then update len maxi with max of l and maxi 
    // with 1 if maxi is already > 0
    // -> this is another window of 1 so return immediately
    // at last update maxi and check if maxi > 0 for final ans
    bool getWindow(string s){
        int l = 0, maxi=0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                // if maxi > 0 -> already another window of 1s is present
                // return false
                if(maxi > 0){
                    return 0;
                }
                // update curr window len
                l++;
            } else {
                // update window len of 1s
                maxi = max(l, maxi);
                // set curr window len to 0
                l = 0;
            }
        }
        // update window len of 1s
        maxi = max(maxi, l);
        // if maxi > 0 then only 1 valid window so true
        return maxi > 0;
    }

    // since s[0] = '1'
    // so we can capture first 0 to right 
    // then starting from there, we should not find any other 1 in remaining str
    // [1 1 0(first 0) 0 1] -> false
    // [1 1 0(first 0) 0 0] -> true
    bool checkAny1After0(string s){
        int first0 = 0;
        for(auto i: s){
            if(i=='0'){
                first0 = i;
                break;
            }
        }
        // no 0 all 1s 
        // only last is 0
        if(first0 == 0 || frist0 == s.size()-1){
            return 1;
        }

        for(int i = first0;i<s.size();i++){
            if(s[i]=='1'){
                return 0;
            }
        }

        return 1;
    }
    bool checkOnesSegment(string s) {
        // return getWindow(s);
        return checkAny1After0(s);
    }
};