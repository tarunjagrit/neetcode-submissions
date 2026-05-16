class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_max=nums[0];
        int pre_min= nums[0];
        int ans=nums[0];

        for(int i=1; i<nums.size(); i++){
            int temp=nums[i];

            int curr_min= min({temp, temp*pre_max, temp*pre_min});
            int curr_max= max({temp, temp*pre_max, temp*pre_min});
            
            ans=max(ans,curr_max);

            pre_max=curr_max;
            pre_min=curr_min;
        }

        return ans;
    }
};