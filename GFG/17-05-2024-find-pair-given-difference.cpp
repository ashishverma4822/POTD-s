class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_map<int,bool>mp;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(x+arr[i])!=mp.end()) return 1;
            else if(mp.find(arr[i]-x)!=mp.end()) return 1;
            mp[arr[i]]=true;
        }
        return -1;
    }
};
