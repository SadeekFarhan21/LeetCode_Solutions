class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> open(n + 1, 0);
        for(int i = 0; i < n; i++) {
            open[i + 1] = open[i] + (customers[i] == 'N' ? 1 : 0);
        }

        vector<int> close(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            close[i] = close[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }
        
        int answer = 0;
        int min_penalty = INT_MAX;
        

        for(int i = 0; i <= n; i++){
            int total_fine = open[i] + close[i];
            if(total_fine < min_penalty){
                answer = i;
                min_penalty = total_fine;
            }
        }
        return answer;
    }
};