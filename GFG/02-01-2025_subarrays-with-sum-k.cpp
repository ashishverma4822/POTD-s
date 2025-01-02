class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int cnt = 0,sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) cnt++; 
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};
