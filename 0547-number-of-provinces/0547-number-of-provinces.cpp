class Solution {
public:
    void dfs(int node, vector <vector<int>> &adj_list, vector <bool> &visited){
        visited[node] = true;
        for(int neighbor : adj_list[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj_list, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <vector <int>> adj_list(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adj_list[i].push_back(j);
                }
            }
        }
        int answer = 0;
        vector <bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++;
                dfs(i, adj_list, visited);
            }
        }
        return answer;
    }
};