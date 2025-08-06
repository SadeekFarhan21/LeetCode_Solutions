class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = INT_MIN;
        while(left < right){
            answer = max(answer, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]){
                left += 1;
            }
            else {
                right -= 1;
            }
        }
        return answer;
    }
};