class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<arr.size();i++){
            mp1[arr[i]]++;
        }
        for(auto i:mp1){
            mp2[i.second]++;
        }
        for(auto i:mp2){
            if(i.second>1){
                return false;
            }
        }
        return true;
    }
};
