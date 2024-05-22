class Solution {
private:    
    bool check_palin(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helpme(string s,int start,vector<string>&t,vector<vector<string>>&v){
        if(start>=s.size()){
            v.push_back(t);
            return;
        }
        string str="";
        for(int i=start;i<s.size();i++){
            str.push_back(s[i]);
            if(check_palin(str)){
                t.push_back(str);
                helpme(s,i+1,t,v);
                cout<<str<<endl;
                t.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>t;
        helpme(s,0,t,v);
        return v;
    }
};
