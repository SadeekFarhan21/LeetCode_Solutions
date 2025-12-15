class Solution {
public:
    int maxSum(vector<int>& nums) {
        set <int> s(nums.begin(), nums.end());
        vector <int> v(s.begin(), s.end());
        int max = *max_element(v.begin(), v.end());
        if(max < 0){
            return max;
        }
        int sum = 0;
        for(auto c : s){
            if(c > 0){
                sum += c;
            }
        }
        return sum;
    }
};