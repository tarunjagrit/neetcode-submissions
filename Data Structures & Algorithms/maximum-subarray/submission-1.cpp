class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre_max=nums[0];
        int ans=nums[0];

        for(int i=1; i<nums.size(); i++){
            int temp=nums[i];

            int curr_max= max({temp, temp+pre_max});
            //int curr_min= min({temp, temp+pre_max});

            ans= max(ans, curr_max);
            pre_max=curr_max;
        }
        return ans;
    }
};