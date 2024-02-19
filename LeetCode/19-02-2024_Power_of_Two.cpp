class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(bitscount(n)==1){
           return 1;
       }
       else{
           return 0;
       }
    }
private:
    int bitscount(int n){
    int count=0;
        while(n>0){
            if(n&1){
                count++;
            }
            n>>=1;
        }
        return count;
    }
};
