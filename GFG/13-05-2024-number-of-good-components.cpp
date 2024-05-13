class Solution {
  private:
    void helpme(int src,unordered_map<int,vector<int>>&mp,vector<int>&vis,vector<pair<int,int>>&check_mp,int &node){
        vis[src]=true;
        node++;
        for(auto nbr:mp[src]){
            check_mp.push_back({src,nbr});
            if(!vis[nbr]){
                helpme(nbr,mp,vis,check_mp,node);
            }
        }
    }
    bool dfs(int src, unordered_map<int,vector<int>>&mp,vector<int>&vis){
        vector<pair<int,int>>check_mp;
        int node=0;
        helpme(src,mp,vis,check_mp,node);
        // cout<<check_mp.size()<<" "<<node<<endl;
        if(check_mp.size()/2==(node*(node-1))/2){
            
            return true;
        }
        else return false;
    }
  public:
    int findNumberOfGoodComponent(int e, int n, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>mp;
        n=n+1;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,false);
        int cnt=0;
        for(int i=1;i<n;i++){
            if(!vis[i] and dfs(i,mp,vis)){
                cnt++;
            }
        }
        return cnt;
    }
};
