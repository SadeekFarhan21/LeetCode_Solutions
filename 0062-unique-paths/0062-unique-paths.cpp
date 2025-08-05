class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m, vector <int> (n, 0));
        // Fill out the last row with 1s
        // Here m is the row index and n is the column index
        
        for(int i = 0; i < n; i++){
            dp[m - 1][i] = 1;
        }

        // Process the last column
        for(int i = 0; i < m - 1; i++){
            dp[i][n - 1] = 1;
        }
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};