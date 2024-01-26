class Solution {
private:
    int mod=1e9+7;
    int helpme(int m,int n,int i,int j, int remMove,vector<vector<vector<int>>>&dp){
        if(i==m or j==n or i<0 or j<0) return 1;
        if(remMove == 0) return 0;

        if(dp[i][j][remMove] != -1) return dp[i][j][remMove];

        return dp[i][j][remMove] = ((helpme(m,n,i+1,j,remMove-1,dp)
                                 + helpme(m,n,i-1,j,remMove-1,dp))%mod
                                 + (helpme(m,n,i,j+1,remMove-1,dp)
                                 + helpme(m,n,i,j-1,remMove-1,dp))%mod)%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return helpme(m,n,startRow,startColumn,maxMove,dp);
    }
};
