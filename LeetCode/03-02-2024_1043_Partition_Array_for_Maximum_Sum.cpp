class Solution {
private:
    int helpme(vector<int>&nums , int i , int k , vector<int>&dp){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        int n = nums.size();
        for(int j = i ; j<min(i+k,n); j++){
            len++;
            maxi = max(maxi,nums[j]);
            int sum = len * maxi + helpme(nums,j+1,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i]=maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helpme(arr,0,k,dp);
    }
};
