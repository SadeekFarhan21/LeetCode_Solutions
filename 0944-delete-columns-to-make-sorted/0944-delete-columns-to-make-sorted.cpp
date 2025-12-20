class Solution {
public:
    bool is_same(vector <char> &sorted, vector <char> &unsorted){
        for(int i = 0; i < sorted.size(); i++){
            if(sorted[i] != unsorted[i]){
                return 1;
            }
        }
        return 0;
    }
    
    int minDeletionSize(vector<string>& strs) {
        int answer = 0;
        for(int i = 0; i < strs[0].size(); i++){
            vector <char> unsorted;
            for(int j = 0; j < strs.size(); j++){
                unsorted.push_back(strs[j][i]);
            }
            vector <char> sorted(unsorted.begin(), unsorted.end());
            sort(sorted.begin(), sorted.end());
            answer += is_same(sorted, unsorted);
        }
        return answer;
    }
};