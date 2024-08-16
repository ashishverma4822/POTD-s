class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int uttar = 0;
        int min_ele = *max_element(arrays[0].begin(),arrays[0].end());
        int max_ele = *min_element(arrays[0].begin(),arrays[0].end());
        for(int i=0;i<arrays.size();i++){
            int maxi = arrays[i][0];
            int mini = arrays[i][0];
            for(int j=0;j<arrays[i].size();j++){
                maxi = max(maxi,arrays[i][j]);
                mini = min(mini,arrays[i][j]);
            }
            uttar = max(uttar,max(max_ele-mini,maxi-min_ele));
            max_ele = max(max_ele,maxi);
            min_ele = min(min_ele,mini);
        }
        return uttar;
    }
};
