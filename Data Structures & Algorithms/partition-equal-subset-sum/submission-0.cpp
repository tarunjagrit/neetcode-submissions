class Solution {
public:
    int func(vector<int>& nums, int target, int start, vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        if(start==nums.size()){
            return false;
        }
        if(dp[start][target]!=-1){
            return dp[start][target];
        }
        bool take = func(nums, target- nums[start], start+1, dp);
        bool skip = func(nums, target, start+1, dp);

        bool fina=take || skip;
        dp[start][target] = fina;

        return fina;

    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> dp(n+1, vector<int> (target+1,-1));

        bool ans= func(nums, target, 0, dp);
        return ans;
    }
};