class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map <int, int> m;
        for(int i = 0; i < edges.size(); i++){
            int edge1 = edges[i][0];
            int edge2 = edges[i][1];
            m[edge1] += 1;
            m[edge2] += 1;
        }
        int max_edge = 0, answer = 0;
        for(auto x : m){
            if(x.second > max_edge){
                answer = x.first;
                max_edge = x.second;
            }
        }
        return answer;
    }
};