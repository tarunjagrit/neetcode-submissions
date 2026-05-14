class Solution {
public:
    int func(vector<int>& nums, vector<int> &dp, int start, int size){
        if(start>=size){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int rob = nums[start]+func(nums, dp, start+2, size);

        int skip = func(nums, dp, start+1, size);
        
        dp[start]=max(rob, skip);
        return dp[start] ;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp(n, -1);

        int ans= func(nums, dp, 0, n);
        
        return ans;
    }
};