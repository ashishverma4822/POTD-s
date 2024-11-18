class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>pre(n,code[0]);
        vector<int>suff(n,code[n-1]);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+code[i];
        }
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1]+code[i];
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(k>0){
                if((i+k+n)%n>i){
                    v.push_back(pre[(i+k+n)%n]-pre[i]);
                }
                else v.push_back(pre[n-1]-pre[i]+pre[(i+k+n)%n]);
            }
            else if(k<0){
                if((i-abs(k)+n)%n<i){
                    v.push_back(suff[(i-abs(k)+n)%n]-suff[i]);
                }
                else v.push_back(suff[0]-suff[i]+suff[(i-abs(k)+n)%n]);
            }
            else v.push_back(0);
        }
        return v;
    }
};
