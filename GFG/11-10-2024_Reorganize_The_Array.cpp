class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>v(arr.size());
        for(int i=0;i<arr.size();i++){
            if(mp.find(i)!=mp.end()){
                v[i]=i;
            }
            else v[i] = -1;
        }
        return v;
    }
};
