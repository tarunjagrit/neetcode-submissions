class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            int count=0;
            for(int j=i+1; j<n; j++){
                if(temperatures[j]>temperatures[i]){
                    count++;
                    ans[i]=count;
                    break;
                }
                count++;
            }
        }
        return ans;
    }
};
