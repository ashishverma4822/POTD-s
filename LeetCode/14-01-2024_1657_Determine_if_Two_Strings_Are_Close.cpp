class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int s1[26]={0},s2[26]={0},sf1[26]={0},sf2[26]={0};
        for(int i=0;i<word1.size();i++){
            s1[word1[i]-'a']++;
            sf1[word1[i]-'a']=1;
        }
        for(int i=0;i<word2.size();i++){
            s2[word2[i]-'a']++;
            sf2[word2[i]-'a']=1;
        }
        sort(s1,s1+26);
        sort(s2,s2+26);
        int t1=0,t2=0;
        for(int i=0;i<26;i++){
            if(s1[i]!=s2[i]) t1=1;
            if(sf1[i]!=sf2[i]) t2=1;
        }
        if(t1==1 || t2==1) return false;
        else return true;
    }
};
