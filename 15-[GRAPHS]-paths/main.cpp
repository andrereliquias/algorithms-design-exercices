#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

/**
 * @brief Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a graph.
 *
 * @param s The source node.
 * @param cities The graph as an adjacency list, where each node has a list of pairs (neighbor, weight).
 * @param dist The distance array to store the shortest distance from the source node to each node.
 */
void dijkstra(int s, vector<vector<pair<int, int>>> &cities, vector<int> &dist)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  // start in s with distance 0
  q.push(make_pair(0, s));
  dist[s] = 0;

  while (!q.empty())
  {
    // w = distance to a
    auto [w, a] = q.top();
    q.pop();

    // if already visited a with a smaller distance, continue
    if (dist[a] < w)
      continue;

    // for each edge a -> b with weight
    for (auto &[b, weight] : cities[a])
    {
      // edge relaxation
      if ((dist[a] + weight) < dist[b])
      {
        dist[b] = dist[a] + weight;
        q.push(make_pair(dist[b], b));
      }
    }
  }
}

/**
 * @brief Main function.
 *
 * Giver a graph with nodes and edges representing cities and paths, find the minimum cost to travel from city 1 to city n
 * with a discount on only one edge.
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

  // original graph and inverted graph
  vector<vector<pair<int, int>>> cities(n), iCities(n);
  // edges to add the discount later
  vector<tuple<int, int, int>> edges(m);

  for (int i = 0; i < m; ++i)
  {
    int a, b;
    int w;
    cin >> a >> b >> w;

    cities[a - 1].push_back(make_pair(b - 1, w));
    iCities[b - 1].push_back(make_pair(a - 1, w));
    edges.emplace_back(a - 1, b - 1, w);
  }

  vector<int> dist(n, INT_MAX), iDist(n, INT_MAX);
  dijkstra(0, cities, dist);
  dijkstra(n - 1, iCities, iDist);

  // apply the discont to the edges
  int minCost = INT_MAX;
  for (auto &[a, b, w] : edges)
  {
    if (dist[a] < INT_MAX && iDist[b] < INT_MAX)
    {
      minCost = min(minCost, dist[a] + iDist[b] + (w / 2));
    }
  }

  cout << minCost << endl;

  return 0;
}
