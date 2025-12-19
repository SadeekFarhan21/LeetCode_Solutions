class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, int length, int width, int dx[], int dy[]){
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < length && ny >= 0 && ny < width && !visited[nx][ny] && grid[nx][ny] == '1'){
                dfs(grid, visited, nx, ny, length, width, dx, dy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int answer = 0;
        int length = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> visited(length, vector <bool> (width, false)); 
        for(int i = 0; i < length; i++){
            for(int j = 0; j < width; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    answer++;
                    dfs(grid, visited, i, j, length, width, dx, dy);
                }
            }
        }
        return answer;
    }
};