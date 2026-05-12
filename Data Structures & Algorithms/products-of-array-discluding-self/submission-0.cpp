class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int product=1;
            for(int j=i+1; j<i+nums.size(); j++){
                product=product*nums[j%nums.size()];
            }
            ans.push_back(product);
        }
        return ans;
    }
};
