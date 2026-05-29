class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;

                if(i == 0 || grid[i-1][j] == 0) count++; // up
                if(i == n-1 || grid[i+1][j] == 0) count++; // down
                if(j == 0 || grid[i][j-1] == 0) count++; // left
                if(j == m-1 || grid[i][j+1] == 0) count++; // right;
            }
        }

        return count;
    }
};