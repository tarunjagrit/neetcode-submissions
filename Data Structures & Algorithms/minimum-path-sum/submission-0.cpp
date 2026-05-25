class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    int func(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& grid){
    
        if(!isValid(i,j,m,n)){
            return INT_MAX;
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=  func(i, j+1, m, n, dp, grid);
        int down=  func(i+1, j, m, n, dp, grid);
        
        if(min(right, down)==INT_MAX){
            return dp[i][j] = INT_MAX;
        }
        dp[i][j]= grid[i][j] + min(right, down);

        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        int ans= func(0,0, m, n, dp, grid);
        return ans;
    }
};