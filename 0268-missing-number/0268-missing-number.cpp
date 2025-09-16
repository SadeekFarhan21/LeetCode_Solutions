class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int i = 1; i <= n; i++){
            answer ^= i;
        }
        for(int i = 0; i < nums.size(); i++){
            answer ^= nums[i];
        }
        return answer;
    }
};