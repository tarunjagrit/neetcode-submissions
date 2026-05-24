class Solution {
public: 
    bool isValid(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n){
        if(i<m && i>=0 && j<n && j>=0 && obstacleGrid[i][j]!=1){
            return true;
        }
        return false;
    }

    int func(vector<vector<int>>& obstacleGrid, int i, int j, int m , int n, vector<vector<int>> &dp){
        if(!isValid(obstacleGrid, i, j, m, n)){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right= func(obstacleGrid, i,j+1,m,n,dp);
        int down= func(obstacleGrid, i+1,j,m,n,dp);
        dp[i][j]=right+down;

        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector< vector<int> >dp(m, vector<int> (n, -1));
        int ans= func(obstacleGrid, 0,0,m,n, dp);
        return ans; 
    }
};