class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        while(k--){
            int t = pq.top();
            pq.pop();
            t--;
            pq.push(t);
        }
        int ans = 0;
        while(!pq.empty()){
            int t= pq.top();
            ans+=t*t;
            pq.pop();
        }
        return ans;
    }
};
