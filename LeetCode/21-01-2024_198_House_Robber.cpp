class Solution {
public:
    int rob(vector<int>& nums) {
        int incl = nums[0];
        int exclu = 0;
        for(int i=1;i<nums.size();i++){
            int newexclu = max(incl,exclu);
            int newincl=nums[i]+exclu;
            incl=newincl;
            exclu=newexclu;
        }
        return max(incl,exclu);
    }
};
