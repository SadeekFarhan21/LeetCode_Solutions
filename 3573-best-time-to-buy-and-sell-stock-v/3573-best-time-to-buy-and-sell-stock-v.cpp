class Solution {
public:
    // 0 = passing, 1 = normal, 2 = short selling
    long long f(int i, int status, int remaining_transactions, vector <int>& prices, vector<vector<vector<long long>>>& dp){  // transaction[i], status, price
        if(remaining_transactions == 0){
            return 0;
        }
        if(i == prices.size() - 1){
            if(status == 0) return 0;
            if(status == 1) return prices[i];
            return -prices[i];
        }
        if(dp[i][status][remaining_transactions] != INT_MIN){
            return dp[i][status][remaining_transactions];
        }
        long long answer = INT_MIN;

        // pass to the next round
        answer = max(answer, f(i + 1, status, remaining_transactions, prices, dp));
        if(status == 0){
            // buy
            answer = max(answer, prices[i] + f(i + 1, 2, remaining_transactions, prices, dp));
            // setl
            answer = max(answer, -prices[i] + f(i + 1, 1, remaining_transactions, prices, dp));
        }
        // already bought now have to sell
        else if (status == 1){
            answer = max(answer, prices[i] + f(i + 1, 0, remaining_transactions - 1, prices, dp));
        }
        else {
            answer = max(answer, -prices[i] + f(i + 1, 0, remaining_transactions - 1, prices, dp));
        }
        return dp[i][status][remaining_transactions] = answer;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (3, vector <long long> (k + 1, INT_MIN))); //  
        return f(0, 0, k, prices, dp);
    }

};