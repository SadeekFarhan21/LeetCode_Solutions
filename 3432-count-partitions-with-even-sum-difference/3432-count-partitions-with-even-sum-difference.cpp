class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector <int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int sum = prefix[nums.size() - 1];
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            int left_sum = prefix[i - 1];
            int right_sum = sum - left_sum;
            if(abs(prefix[i - 1] - (sum - prefix[i - 1])) % 2 == 0){
                count += 1;
            }
            // cout << left_sum << " " << right_sum << "\n";
        }
        return count;
    }
};