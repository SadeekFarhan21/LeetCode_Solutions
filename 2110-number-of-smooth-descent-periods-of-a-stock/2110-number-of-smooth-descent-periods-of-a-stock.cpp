class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long answer = 1;

        long long day_counter = 1;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i - 1] - prices[i] == 1){
                day_counter += 1;
            }
            else {
                day_counter = 1;
            }
            answer += day_counter;
        }
        return answer;
    }
};