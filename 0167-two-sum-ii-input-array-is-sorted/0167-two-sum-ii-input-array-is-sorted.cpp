class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector <int> answer(2);
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else if(sum == target){
                answer[0] = left + 1;
                answer[1] = right + 1;
                break;
            }
        }
        return answer;
    }
};