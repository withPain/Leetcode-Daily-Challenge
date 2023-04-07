class Solution {

private:
void dfs(vector<vector<int>>& grid, int i, int j) {

  if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
  return;

  if (grid[i][j] == 0)
  return;

  grid[i][j] = 0;

  dfs(grid, i + 1, j);
  dfs(grid, i - 1, j);
  dfs(grid, i, j + 1);
  dfs(grid, i, j - 1);
};

public:
    int numEnclaves(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    // Remove lands connected to edge
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (grid[i][j] == 1)
            dfs(grid, i, j);

    int ans = 0;

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (grid[i][j] == 1) {
          ans++;
        }

    return ans;
    }
};