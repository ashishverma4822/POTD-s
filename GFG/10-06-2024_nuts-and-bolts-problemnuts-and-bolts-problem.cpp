class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int>mp,mp2;
        mp['!']=0; mp['#']=1; mp['$']=2; mp['%']=3; mp['&']=4; mp['*']=5; mp['?']=6; mp['@']=7; mp['^']=8;
        mp2[0]='!'; mp2[1]='#'; mp2[2]='$'; mp2[3]='%'; mp2[4]='&'; mp2[5]='*'; mp2[6]='?'; mp2[7]='@'; mp2[8]='^';
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=mp[nuts[i]];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            nuts[i] = mp2[v[i]];
            bolts[i] = mp2[v[i]];
        }
    }
};
