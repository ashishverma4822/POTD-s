class Solution {
private: 
    bool hiAyu(char s){
        if(s=='a' or s=='e' or s=='i' or s=='o' or s=='u') return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(hiAyu(words[i][0]) and hiAyu(words[i][words[i].size()-1])) v[i] = 1;
        }
        for(int i=1;i<words.size();i++){
            v[i] = v[i-1]+v[i];
        }
        vector<int> uttar;
        for(int i=0;i<queries.size();i++){
            int f = queries[i][1];
            int n = queries[i][0];
            if(n==0) uttar.push_back(v[f]);
            else uttar.push_back(v[f]-v[n-1]);
        }
        return uttar;
    }
};
