class Solution {
public:
    vector<int> prevSmaller(vector<int> &v){
        vector<int> arr(v.size());
        stack<int> st;
        for(int i =0;i<v.size();i++){
            while(!st.empty() && v[i] <= v[st.top()]){
                st.pop();
            }

            arr[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return arr;
    }
    vector<int> nextSmaller(vector<int> &v){
        vector<int> arr(v.size());
        stack<int> st;
        for(int i =v.size()-1;i>=0;i--){
            while(!st.empty() && v[i] <= v[st.top()]){
                st.pop();
            }

            arr[i]=st.empty()? -1: st.top();
            st.push(i);
        }
        return arr;
    }

    int areaHistogram(vector<int> &v){
        vector<int> prevSmallerIndex = prevSmaller(v);
        vector<int> nextSmallerIndex = nextSmaller(v);
        int ans = 0;
        for(int i =0;i<v.size();i++){
            if(nextSmallerIndex[i] == -1)
                nextSmallerIndex[i] = v.size();
            int w = (nextSmallerIndex[i] - prevSmallerIndex[i]-1);
            ans = max(ans, v[i]*w);
        // cout<<v[i]<<nextSmallerIndex[i] << prevSmallerIndex[i]<<" "<<ans<<endl;
        }
        return ans;
    }

    int opt(vector<vector<char>> &matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<int> arr(m, 0);
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]=='1')
                arr[i]++;
        }
        int ans=areaHistogram(arr);
        for(int i=1;i<n;i++){
            for(int j = 0; j<m;j++){
                if(matrix[i][j] == '0'){
                    arr[j]=0;
                }else{
                    arr[j]++;
                }
            }
            ans = max(ans, areaHistogram(arr));
        }
        return ans;
    }

    vector<vector<int>> convert(vector<vector<char>>& matrix){
        vector<vector<int>>ans(matrix.size(), vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++){
            for(int j = 0; j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    ans[i][j]=1;
                }
            }
        }
        return ans;
    }
    int brute(vector<vector<int>> &arr){
        int row = arr.size(), col = arr[0].size();
        int ans= 0;
        for(int i=0;i<row;i++){
            for(int j = 0; j<col;j++){
                if(i>0 &&arr[i][j]==1){
                    arr[i][j]+=arr[i-1][j];
                }
            }
        }   

        for(int i =0;i<row;i++){
            for(int j = 0; j<col;j++){
                if(arr[i][j]>0){
                    // get next smaller elem
                    int nextSmall = j;
                    while(nextSmall<col && arr[i][j] <= arr[i][nextSmall]){
                        nextSmall++;
                    }
                    // get prev smaller elem
                    int prevSmall = j;
                    while(prevSmall>=0 && arr[i][j] <= arr[i][prevSmall]){
                        prevSmall--;
                    }
                   
                    // area = h * (b)
                    int area = arr[i][j] * (nextSmall - prevSmall-1);
                    // cout<<arr[i][j] <<nextSmall <<prevSmall<<area<<endl;

                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // vector<vector<int>> arr = convert(matrix);
        // return brute(arr);
        
        return opt(matrix);
    }
};