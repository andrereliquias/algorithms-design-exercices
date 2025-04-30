#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

/**
 * Finds the number of paths between the origin and destination of a grid maze with obstacles,
 * being able to move only to the right or downwards.
 *
 * @param grid The maze.
 * @param memo The memoization table.
 * @param n The grid size.
 */
int solve(vector<vector<int>> &grid, vector<vector<int>> &memo, int n)
{
  if (grid[0][0])
  {
    memo[0][0] = 1;
  }

  for (int i = 1; i < n; i++)
  {
    if (grid[i][0] && memo[i - 1][0] > 0)
    {
      memo[i][0] = memo[i - 1][0];
    }
  }

  for (int j = 1; j < n; j++)
  {
    if (grid[0][j] && memo[0][j - 1] > 0)
    {
      memo[0][j] = memo[0][j - 1];
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (grid[i][j])
      {
        memo[i][j] += (memo[i - 1][j] + memo[i][j - 1]) % MOD;
      }
    }
  }
  return memo[n - 1][n - 1];
}

/**
 * @brief Main function.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 *
 * @return `0` if sucess.
 */
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  vector<vector<int>> memo(n, vector<int>(n, 0));
  vector<vector<int>> grid(n, vector<int>(n, 1));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      char c;
      cin >> c;
      if (c == '*')
        grid[i][j] = 0;
    }

  int res = solve(grid, memo, n);
  cout << res << endl;

  return 0;
}
