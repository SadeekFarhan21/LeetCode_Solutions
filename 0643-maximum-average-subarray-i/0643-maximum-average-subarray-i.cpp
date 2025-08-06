class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int answer = sum;
        for(int i = k; i < nums.size(); i++){
            sum = sum + nums[i] - nums[i - k];
            answer = max(answer, sum);
        }
        return (double) answer / k;
    }
};