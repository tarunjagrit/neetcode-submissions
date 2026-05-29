class Solution {
public:
    int func(int idx, string &s, vector<int> &dp){
        if(idx==s.size()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int go1 = func(idx+1 , s, dp);
        int go2=0;
        if(idx+1 < s.size()){
            int num = stoi(s.substr(idx, 2));
            if(num >=10 && num<27){
                go2= func(idx+2, s, dp);
            }
        }

        return dp[idx]=go1 + go2;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n, -1);
        int ans=func(0, s, dp);
        return ans;
    }
};