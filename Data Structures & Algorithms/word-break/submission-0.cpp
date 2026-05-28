class Solution {
public:
    unordered_set<string> st;
    bool func(int idx, string &s, vector<int> &dp){
        if(idx==s.size()){
            return true;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        for(int length=1; length+idx<=s.size(); length++){
            string temp = s.substr(idx, length);
            if(st.find(temp)!=st.end() && func(idx+length, s, dp)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1, -1);
        for(string &word: wordDict){
            st.insert(word);
        }
        bool ans= func(0, s, dp);
        return ans;
    }
};