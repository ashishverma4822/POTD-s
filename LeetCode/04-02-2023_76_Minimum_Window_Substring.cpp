class Solution {
public:
    string minWindow(string s, string p) {
        if(s==p){
            return s;
        }
        if(p.size()>s.size()){
            return "";
        }
        unordered_map<char,int>mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int count=mp.size();
        int i=0,j=0;
        int res=-1;
        pair<int,int>pa={0,0};
        string g="";
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
	                count--;
	            }
            }
	        if(count==0){
	            while(count==0){
	                if(mp.find(s[i])!=mp.end()){
	                    mp[s[i]]++;
	                    if(mp[s[i]]==1){
	                        count++;
	                    }
	                }
	                i++;
	            }
	            if(j-i+2<res || res==-1){
	                res=j-i+2;
	                pa.first=i-1;
	                pa.second=j;
	            }
	        }
	        j++;
        }
        if(res==-1){
            return "";
        }
        for(int l=pa.first;l<=pa.second;l++){
            g.push_back(s[l]);
        }
        return g;
    }
};
