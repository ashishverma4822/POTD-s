class Solution{
private:
    void helpme(int s,int m,int n,int & cnt){
        if(n==0){
            cnt++;
            return;
        }
        for(int i=s;i*pow(2,n-1)<=m;i++){
            helpme(i*2,m,n-1,cnt);
        }
    }
public:
    int numberSequence(int m, int n){
        // code here
        if(n==1) return m;
        int cnt=0;
        for(int i=1;i<i*pow(2,n-1) and i<m;i++){
            helpme(i*2,m,n-1,cnt);
        }
        return cnt;
    }
};
