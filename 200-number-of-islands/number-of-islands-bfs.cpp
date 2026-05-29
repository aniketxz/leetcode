class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                if(grid[i][j] == '0') continue;

                islands++;

                // bfs
                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for(auto &[dx, dy] : dir) {
                        int nx = x + dx;
                        int ny = y + dy;

                        if(nx >= 0 && ny >= 0 &&
                            nx < rows && ny < cols && 
                            grid[nx][ny] == '1') {

                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                    }
                }
            }
        }

        return islands;
    }
};
