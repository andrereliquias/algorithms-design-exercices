#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * @brief Given the distance of the trails that lead to the lakes in dist, find the smallest sum of the distances of the trails chosen to visit all of them, starting from lake 1.
 *
 * @param u current lake
 * @param currentMask bitmask from visited lakes
 * @param maskAllLakes bitmask from all lakes
 * @param dist mapping from lake u to v with distance d
 * @param memo memorization table
 * @param n number of lakes
 *
 * @return minimun cost to visit all lakes
 */
long long solve(int u, int currentMask, int &maskAllLakes, vector<vector<long long>> &dist, vector<vector<long long>> &memo, int n)
{
  if (currentMask == maskAllLakes)
    return 0;

  long long &cost = memo[currentMask][u];
  if (cost != -1)
    return cost;

  cost = INT_MAX;
  for (int v = 0; v < n; v++)
  {
    if ((currentMask & (1 << v)) == 0 && dist[u][v] < INT_MAX)
    {
      cost = min(cost, dist[u][v] + solve(v, currentMask | (1 << v), maskAllLakes, dist, memo, n));
    }
  }
  return cost;
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
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));

  for (int i = 0; i < n; i++)
    dist[i][i] = 0;

  for (int i = 0; i < m; i++)
  {
    int u, v, d;
    cin >> u >> v >> d;
    dist[u - 1][v - 1] = d;
    dist[v - 1][u - 1] = d;
  }

  int maskAllLakes = (1 << n) - 1;
  vector<vector<long long>> memo(1 << n, vector<long long>(n, -1));

  long long res = solve(0, 1 << 0, maskAllLakes, dist, memo, n);
  if (res >= INT_MAX)
    res = -1;
  cout << res;

  return 0;
}
