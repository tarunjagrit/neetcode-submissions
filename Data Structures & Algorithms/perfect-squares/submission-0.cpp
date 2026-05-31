class Solution {
public:
    int func(int idx, int target, vector<vector<int>> &dp){
        if(target==0){
            return 0;
        }
        if(idx>target/idx){
            return 1e9;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int skip= func(idx+1, target, dp);
        int take=1e9;
        if(idx<=target/idx){
            take= 1 + func(idx, target-idx*idx, dp);
        }

        return dp[idx][target]= min(take,skip);
    }
    int numSquares(int n) {
        int limit = sqrt(n);
        vector< vector<int>> dp(limit+1, vector<int> (n+1,-1));
        int ans= func(1, n, dp);
        return ans;
    }
};