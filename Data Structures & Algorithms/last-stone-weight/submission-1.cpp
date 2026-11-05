class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        priority_queue<int> pq;

        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int hi=pq.top();
            pq.pop();
            int sec_hi=pq.top();
            pq.pop();

            int diff= abs(sec_hi-hi);
            pq.push(diff);
        }

        int ans=pq.top();
        return ans;
    }
};
