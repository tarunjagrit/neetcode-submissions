class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s= nums.size();
        vector<int> presum(nums.size());
        vector<int> aftersum;

        int product=1;
        aftersum.push_back(product);
        for(int i=1; i<nums.size(); i++){
            product=product*nums[i-1];
            aftersum.push_back(product);
        }

        int product2=1;
        presum[s-1]=product2;
        for(int j=s-2; j>=0; j--){
            product2=product2*nums[j+1];
            presum[j]=product2;
        }
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            answer.push_back(presum[i]*aftersum[i]);
        }
        return answer;
    }
};
