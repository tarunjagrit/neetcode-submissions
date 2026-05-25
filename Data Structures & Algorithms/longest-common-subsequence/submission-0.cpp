class Solution {
public:
    int func(int i, int j, int n, int m,string &text1, string &text2, vector<vector<int>> &dp){
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1 + func(i+1,j+1, n, m, text1, text2, dp);
        }
        int right=func(i+1,j, n, m, text1, text2, dp);
        int left =func(i,j+1, n, m, text1, text2, dp);

        dp[i][j]= max(right,left);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans= func(0,0, n, m, text1, text2, dp);
        return ans;
    }
};