class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = INT_MIN;
        int counter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                counter += 1;
                answer = max(answer, counter);
            }
            else {
                counter = 0;
            }
        }
        if(answer < 0){
            return 0;
        }
        return answer;
    }
};