class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int running_sum = 0;        
        for(int i = 0; i < capacity.size(); i++){
            running_sum += capacity[i];
            if(running_sum >= total_apples){
                return i + 1;
            }
        }
        return 0;
    }
};