class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int t=0;
        int c=0;
        for(int i=0;i<n;i++){
        if(nums[i]==nums[t]){
            c++;
        }
         else{
            c--;
        }
        if(c==0){
            t=i;
            c=1;
        }
    }
    return nums[t]; 
}
};
