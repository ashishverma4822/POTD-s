// TLE Approach Recursive
class Solution1 {
private:
    long long helpme(vector<vector<int>>& points, int i, int j, int row, int col) {
        if (i >= row) return 0; 
        long long max_val = points[i][j];
        i++;
        if (i >= row) return max_val;
        long long best_next = 0;
        for (int c = 0; c < col; c++) {
            long long ans = helpme(points, i, c, row, col) - abs(j-c);
            best_next = max(best_next, ans);
        }
        return max_val + best_next;
    }

public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        long long max_val = 0;
        
        for (int j = 0; j < col; j++) {
            max_val = max(max_val, helpme(points, 0, j, row, col));
        }
        
        return max_val;
    }
};

// TLE Approach Dynamic Programming
class Solution2 {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<vector<long long>> v(row, vector<long long >(col,0));
        for(int i = 0;i<col;i++) v[0][i] = points[0][i];
        for(int k=1;k<row;k++){
            for(int i=0;i<col;i++){
                long long ans = 0;
                for(int j=0;j<col;j++){
                    ans = max(ans,v[k-1][j]-abs(i-j));
                }
                v[k][i] = points[k][i] + ans;
            }
        }
        long long uttar = 0;
        for(int i = 0;i<col;i++) uttar = max(uttar,v[row-1][i]);
        return uttar;
    }
};

// Accepted Code
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<long long> prev(col, 0), curr(col, 0);

        for(int i = 0; i < col; i++) prev[i] = points[0][i];
        for(int k = 1; k < row; k++){
            vector<long long> leftMax(col, 0), rightMax(col, 0);
            leftMax[0] = prev[0];
            for(int i = 1; i < col; i++) {
                leftMax[i] = max(leftMax[i - 1] - 1, prev[i]);
            }
            rightMax[col - 1] = prev[col - 1];
            for(int i = col - 2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i + 1] - 1, prev[i]);
            }
            for(int i = 0; i < col; i++) {
                curr[i] = points[k][i] + max(leftMax[i], rightMax[i]);
            }
            prev = curr;
        }
        long long uttar = 0;
        for(int i = 0; i < col; i++) 
            uttar = max(uttar, prev[i]);
        return uttar;
    }
};
