class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map <int, int> counter;
        for(int i = 1; i <= nums.size(); i++){
            counter[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            counter[nums[i]]++;
        }
        vector <int> answer;
        for(auto x : counter){
            if(x.second == 2){
                answer.push_back(x.first);
            }
        }
        for(auto x : counter){
            if(x.second == 0){
                answer.push_back(x.first);
            }
        }
        return answer;
    }
};