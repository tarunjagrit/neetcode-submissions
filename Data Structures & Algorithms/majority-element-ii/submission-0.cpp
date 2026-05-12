class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int count=1;
        int i;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else if(nums[i]!=nums[i-1]){
                if(count>(nums.size()/3)){
                    v.push_back(nums[i-1]);
                }
                count=1;
            }
        }
        if(count>(nums.size()/3)){
            v.push_back(nums[nums.size()-1]);
        }
        return v;
    }
};