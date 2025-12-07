class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> answers;
        for(int i = 0; i < n; i++){
            answers.push_back(nums[i]);
            answers.push_back(nums[n + i]);
        }
        return answers;
    }
};