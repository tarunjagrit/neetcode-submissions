class Solution {
public:
    int func(int idx, int target, int curr, int count){
        if(target==0){
            if(count>=2){
                return curr;
            }
            return 0;
        }
        if(target<0 || idx>target){
            return 0;
        }
        int skip = func(idx+1, target, curr, count);
        
        int take = func(idx, target-idx, curr*idx, count+1);

        return max(skip, take);
    }
    int integerBreak(int n) {

        int ans = func(1, n, 1, 0);
        return ans;
    }
};