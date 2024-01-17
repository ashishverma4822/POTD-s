class Solution {
  private:
    void helpme(vector<int>&nums,vector<vector<int>>&ans,int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>mp;
        for(int i=start;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }
            mp[nums[i]] = true;
            swap(nums[start],nums[i]);
            helpme(nums,ans,start+1);
            swap(nums[start],nums[i]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>uttar;
        helpme(arr,uttar,0);
        sort(uttar.begin(),uttar.end());
        return uttar;
    }
};
