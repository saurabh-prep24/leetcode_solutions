class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort arr
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        // ans arr
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++){
            // curr diff
            int diff = abs(arr[i]-arr[i-1]);
            // update minDiff and clear existing ans and push curr pair
            if(diff<minDiff){
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }else if(diff == minDiff){
                // keep adding to ans till minDiff is same
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        // return ans
        return ans;
    }
};