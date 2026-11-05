class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n=stones.size();

        while(stones.size()>1){
            int hi=stones[stones.size()-1];
            int sec_hi=stones[stones.size()-2];

            int diff= abs(sec_hi-hi);
            stones.pop_back();
            stones.pop_back();
            stones.push_back(diff);
            sort(stones.begin(), stones.end());
        }

        int ans=stones[0];
        return ans;
    }
};
