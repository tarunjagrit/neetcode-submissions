class Solution {
public:
    int func(vector<int> &prices, int idx, int holding, vector<vector<int>> &dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][holding]!=-1){
            return dp[idx][holding];
        }
        if(holding==0){
            int skip= func(prices, idx+1, 0, dp);
            int buy= -prices[idx]+ func(prices, idx+1, 1, dp);

            return dp[idx][holding]=max(skip, buy);
        }
        else{
            int skip=func(prices, idx+1, 1, dp);
            int sell= prices[idx]+func(prices, idx+2, 0, dp);
            return dp[idx][holding]=max(skip, sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2,-1));
        int ans=func(prices, 0,0, dp);
        return ans;
    }
};