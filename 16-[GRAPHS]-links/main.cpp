#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief Depth First Search (DFS) algorithm
 *
 * It walks through the entire connected component containing `u`,
 * marking the `streets` as `visited` and, at the same time, finds out which is the largest number of neighborhoods present by `max`
 *
 * @param visited A vector to keep track of visited neighborhoods.
 * @param streets A vector of vectors representing the graph.
 * @param u The current node being visited.
 * @param max The maximum node found in the component.
 */
void dfs(vector<int> &visited, vector<vector<int>> &streets, int u, int &max)
{
  visited[u] = 1;
  max = std::max(max, u);
  for (int i = 0; i < streets[u].size(); i++)
  {
    int v = streets[u][i];
    if (visited[v] == 0)
      dfs(visited, streets, v, max);
  }
}

/**
 * @brief Main function.
 *
 * Given `n` neighborhoods and `m` streets in a city, find the minimum number of missing streets
 * for all neighborhoods to be connected and determine which roads connecting 2 neighborhoods
 * need to be built to do so.
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

  vector<vector<int>> streets(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    streets[a - 1].push_back(b - 1);
    streets[b - 1].push_back(a - 1);
  }

  vector<int> visited(n, 0);
  vector<int> links;

  int max = 0;
  dfs(visited, streets, 0, max);
  for (int i = 1; i < n; i++)
  {
    if (visited[i] == 0)
    {
      int comp_max = i;
      dfs(visited, streets, i, comp_max);
      links.push_back(comp_max);
    }
  }

  int minStreets = links.size();
  cout << minStreets << endl;

  for (int i = 0; i < links.size(); i++)
  {
    int link = links[i];
    cout << (max + 1) << " " << (link + 1) << endl;
    max = link;
  }

  return 0;
}
