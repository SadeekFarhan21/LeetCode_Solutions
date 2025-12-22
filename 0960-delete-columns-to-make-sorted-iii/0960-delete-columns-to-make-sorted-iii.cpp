class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size();
        int row = strs.size();
        vector <int> dp(col + 1, 1); 
        int answer = 0;
        for(int i = 0; i < col; i++){
            for(int j = 0; j < i; j++){
                bool safe = true;
                for(int k = 0; k < row; k++){
                    if(strs[k][j] > strs[k][i]){
                        safe = false;
                        break;
                    }
                }
                if(safe){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            } 
            answer = max(answer, dp[i]);
        }   
        return col - answer;
    }
};