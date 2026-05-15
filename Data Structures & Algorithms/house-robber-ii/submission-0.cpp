class Solution {
public:
    int func(vector<int> &dp, vector<int> &nums, int start, int size){
        if(start >= size){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }

        int rob = nums[start] + func(dp, nums, start+2, size);
        int skip = func(dp, nums, start+1, size);

        dp[start]= max(rob,skip);

        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n,-1);
        int ans1= func(dp, nums, 0, n-1);

        vector<int> dp2(n,-1);
        int ans2= func(dp2, nums, 1, n);

        return max(ans1, ans2);
    }
};