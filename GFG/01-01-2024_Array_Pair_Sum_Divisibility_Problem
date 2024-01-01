class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2) return false;
        unordered_map<int,int>mp;
        int t=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]%k)!=mp.end()){
                t++;
                mp.erase(nums[i]%k);
                continue;
            }
            if(mp.find(k-nums[i]%k)!=mp.end()){
                t++;
                mp.erase(k-nums[i]%k);
                continue;
            }
            mp[nums[i]%k]++;
        }
        return nums.size()/2==t;
    }
};
