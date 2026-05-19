class Solution {
public:
    int func(int idx, int target, vector< vector<int> > &dp, vector<int>& coins){
        if(target==0){
            return 0;
        }
        if(idx==coins.size()){
            return 1e9;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int take= 1e9;
        if(coins[idx]<=target){
            take= 1+func(idx, target-coins[idx], dp, coins);
        }
        int skip= func(idx+1, target, dp, coins);

        dp[idx][target] = min(take, skip);

        return dp[idx][target];

    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            else{
                return -1;
            }
        }
        vector< vector<int> > dp(coins.size(), vector<int>(amount+1, -1));

        int ans= func(0,amount, dp, coins);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};