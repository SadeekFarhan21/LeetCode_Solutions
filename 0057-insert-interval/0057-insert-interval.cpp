class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 0; i < intervals.size(); i++){
            if(answer.back()[1] >= intervals[i][0]){
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            }
            else {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};