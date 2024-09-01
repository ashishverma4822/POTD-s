class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n) return {};
        vector<vector<int>> v(m,vector<int>(n));
        int k = 0;
        for(int i=0;i<original.size();i++){
            if(i!=0 and i%n==0) k++;
            v[k%m][i%n] = original[i];
        }
        return v;
    }
};
