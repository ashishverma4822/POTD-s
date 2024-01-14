class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        set<vector<int>>st;
        vector<int>ans;
        for(int i=0;i<M;i++){
            vector<int>v;
            for(int j=0;j<N;j++){
                v.push_back(matrix[i][j]);
            }
            if(st.find(v)!=st.end()) ans.push_back(i);
            else st.insert(v);
        }
        return ans;
    } 
};
