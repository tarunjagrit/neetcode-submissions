class Solution {
public:
    int func(vector<int>& nums, int idx, int prev, vector< vector<int>> &dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int skip= func(nums, idx+1, prev, dp);
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take= 1+func(nums, idx+1, idx, dp);
        }

        dp[idx][prev+1]= max(take, skip);
        return dp[idx][prev+1] ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector< vector<int>> dp(n, vector<int> (n+1,-1));
        int ans= func(nums, 0, -1, dp);
        return ans;
    }
};