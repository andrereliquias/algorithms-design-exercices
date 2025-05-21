#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs1(int u,
          const vector<vector<int>> &planets,
          vector<int> &visited,
          vector<int> &order)
{
  visited[u] = 1;
  for (int v : planets[u])
  {
    if (!visited[v])
    {
      dfs1(v, planets, visited, order);
    }
  }
  order.push_back(u);
}

void dfs2(int u,
          const vector<vector<int>> &iPlanets,
          vector<int> &components,
          int label)
{
  components[u] = label;
  for (int v : iPlanets[u])
  {
    if (components[v] == 0)
    {
      dfs2(v, iPlanets, components, label);
    }
  }
}

pair<int, vector<int>> korasaju(int n,
                                const vector<vector<int>> &planets,
                                const vector<vector<int>> &iPlanets)
{
  vector<int> visited(n, 0);
  vector<int> order;
  order.reserve(n);
  for (int u = 0; u < n; u++)
  {
    if (visited[u] == 0)
    {
      dfs1(u, planets, visited, order);
    }
  }

  vector<int> components(n, 0);
  int numSCC = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    int u = order[i];
    if (components[u] == 0)
    {
      numSCC++;
      dfs2(u, iPlanets, components, numSCC);
    }
  }

  return {numSCC, components};
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> planets(n), iPlanets(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    planets[a - 1].push_back(b - 1);
    iPlanets[b - 1].push_back(a - 1);
  }

  auto [numSCC, components] = korasaju(n, planets, iPlanets);

  cout << numSCC << endl;
  for (int u = 0; u < n; u++)
  {
    cout << components[u] << ' ';
  }
  cout << endl;
  return 0;
}
