class Solution {
public:
    bool isValid(int m, int n, int i, int j){
        if(i<m && i>=0 && j<n && j>=0){
            return true;
        }
        return false;
    }
    int func(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(!isValid(m,n,i,j)){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right= func(m,n, i, j+1, dp);
        int down= func(m,n,i+1,j, dp);

        dp[i][j]= right+down;
        return dp[i][j] ;
    }
    int uniquePaths(int m, int n) {
        vector< vector<int> > dp(m, vector<int>(n,-1));
        int ans = func(m, n, 0,0, dp);
        return ans;
    }
};