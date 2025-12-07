class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        map <int, int> index;
        for(int i = 0; i < nums.size(); i++){
            index.insert({nums_copy[i], i});
        }
        vector <int> answer;
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(index[nums[i]]);
        }
        return answer;
    }
};