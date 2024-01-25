// Recursive Approach
class Solution1 {
private:
    int helpme(string s1,string s2,int i,int j,int n1,int n2){
        if(i>=n1 or j>=n2) return 0;
        if(s1[i]==s2[j]) return 1+helpme(s1,s2,i+1,j+1,n1,n2);
        else return max(helpme(s1,s2,i+1,j,n1,n2),helpme(s1,s2,i,j+1,n1,n2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return helpme(text1,text2,0,0,text1.size(),text2.size());
    }
};

// Recursive Approach 2
class Solution2 {
private:
    int helpme(string s1,string s2,int i,int j){
        if(i<0 or j<0) return 0;
        if(s1[i]==s2[j]) return 1+helpme(s1,s2,i-1,j-1);
        else return max(helpme(s1,s2,i-1,j),helpme(s1,s2,i,j-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return helpme(text1,text2,text1.size()-1,text2.size()-1);
    }
};

// Memoiztion Approach1 
class Solution3 {
private:
    int helpme(string s1,string s2,int i,int j,int n1,int n2,vector<vector<int>>&v){
        if(i>=n1 or j>=n2) return 0;
        if(v[i][j]!=-1) return v[i][j];
        if(s1[i]==s2[j]) return v[i][j]=1+helpme(s1,s2,i+1,j+1,n1,n2,v);
        else return v[i][j]=max(helpme(s1,s2,i+1,j,n1,n2,v),helpme(s1,s2,i,j+1,n1,n2,v));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size()+1,vector<int>(text2.size()+1,-1));
        helpme(text1,text2,0,0,text1.size(),text2.size(),v);
        return v[0][0];
    }
};

// Memoization Appraaoch 2
class Solution4 {
private:
    int helpme(string s1,string s2,int i,int j,vector<vector<int>>&v){
        if(i<0 or j<0) return 0;
        if(v[i][j]!=-1) return v[i][j];
        if(s1[i]==s2[j]) return v[i][j]=1+helpme(s1,s2,i-1,j-1,v);
        else return v[i][j]=max(helpme(s1,s2,i-1,j,v),helpme(s1,s2,i,j-1,v));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size()+1,vector<int>(text2.size()+1,-1));
        helpme(text1,text2,text1.size()-1,text2.size()-1,v);
        return v[text1.size()-1][text2.size()-1];
    }
};

// Tabulation Approach 1
class Solution5 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size()+1,vector<int>(text2.size()+1));
        for(int i=0;i<=text1.size();i++) v[i][0]=0;
        for(int i=0;i<=text2.size();i++) v[0][i]=0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]) v[i][j] = 1+v[i-1][j-1];
                else v[i][j]=max(v[i-1][j],v[i][j-1]); 
            }
        }
        return v[text1.size()][text2.size()];
    }
};

// Tabulation Approach 2

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v(text1.size()+1,vector<int>(text2.size()+1));
        for(int i=0;i<=text1.size();i++) v[i][text2.size()]=0;
        for(int i=0;i<=text2.size();i++) v[text1.size()][i]=0;
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]) v[i][j] = 1+v[i+1][j+1];
                else v[i][j]=max(v[i+1][j],v[i][j+1]); 
            }
        }
        return v[0][0];
    }
};
