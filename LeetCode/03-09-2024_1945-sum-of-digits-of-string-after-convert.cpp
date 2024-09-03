class Solution {
public:
    int getLucky(string s, int k) {
        string t ="";
        for(int i=0;i<s.size();i++){
            t+=to_string(s[i]-'a' + 1);
        }
        while(k--){
            long sum = 0;
            for(int i=0;i<t.size();i++){
                sum+=(t[i]-'0');
            }
            t = to_string(sum);
        }
        return (stoi(t));
    }
};
