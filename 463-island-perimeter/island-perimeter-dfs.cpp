class Solution {
public:
    int rows, cols;

    int dfs(int i, int j,vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0)
            return 1;

        if(vis[i][j])
            return 0;

        vis[i][j] = true;

        int perimeter = 0;

        perimeter += dfs(i-1, j, grid, vis); // up
        perimeter += dfs(i+1, j, grid, vis); // down
        perimeter += dfs(i, j-1, grid, vis); // left
        perimeter += dfs(i, j+1, grid, vis); // right

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 1) {
                    return dfs(i, j, grid, vis);
                }
            }
        }

        return -1;
    }
};
