class Solution {
public:
    int fib(int start, vector<int> &dp){
        if(start<=0){
            return 0;
        }
        if(start==1 || start==2){
            return 1;
        }
        else if(dp[start]!=-1){
            return dp[start];
        }

        dp[start]= fib(start-1,dp) + fib(start-2,dp) + fib(start-3,dp);

        return dp[start];
    }
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        vector<int> dp(n+1, -1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        int ans= fib(n, dp);

        return ans;
    }
};