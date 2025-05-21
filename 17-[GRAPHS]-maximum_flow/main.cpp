#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

void bfs(vector<int> &visited,
         const vector<vector<tuple<int, int, int>>> &streets,
         int s)
{
  queue<int> q;
  q.push(s);
  visited[s] = 1;

  while (!q.empty())
  {
    int a = q.front();
    q.pop();
    for (auto &b : streets[a])
    {
      int v, cap, rev;
      tie(v, cap, rev) = b;
      if (visited[v] == 0 && cap > 0)
      {
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}

int edmondsKarp(int s, int t,
                vector<vector<tuple<int, int, int>>> &streets)
{
  int n = streets.size();
  int flow = 0;

  while (true)
  {
    vector<int> parent(n, -1);
    vector<int> parentEdge(n, -1);
    queue<int> q;
    parent[s] = s;
    q.push(s);

    while (!q.empty() && parent[t] == -1)
    {
      int a = q.front();
      q.pop();
      for (int b = 0; b < streets[a].size(); b++)
      {
        int v, cap, rev;
        tie(v, cap, rev) = streets[a][b];
        if (cap > 0 && parent[v] == -1)
        {
          parent[v] = a;
          parentEdge[v] = b;
          q.push(v);
          if (v == t)
            break;
        }
      }
    }
    if (parent[t] == -1)
      break;

    int aug = INT_MAX;
    for (int v = t; v != s; v = parent[v])
    {
      int a = parent[v];
      int b = parentEdge[v];
      int cap = get<1>(streets[a][b]);
      aug = min(aug, cap);
    }

    for (int v = t; v != s; v = parent[v])
    {
      int a = parent[v];
      int b = parentEdge[v];
      int rev = get<2>(streets[a][b]);
      get<1>(streets[a][b]) -= aug;
      get<1>(streets[v][rev]) += aug;
    }
    flow += aug;
  }

  return flow;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<tuple<int, int, int>>> streets(n);
  vector<pair<int, int>> streetsOrig(m);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    streets[a - 1].push_back(make_tuple(b - 1, 1, streets[b - 1].size()));
    streets[b - 1].push_back(make_tuple(a - 1, 1, streets[a - 1].size() - 1));
    streetsOrig.emplace_back(a - 1, b - 1);
  }

  int s = 0, t = n - 1;
  int flow = edmondsKarp(s, t, streets);

  vector<int> visited(n, 0);
  bfs(visited, streets, s);

  vector<pair<int, int>> answer;
  for (pair<int, int> &e : streetsOrig)
  {
    int a = e.first;
    int b = e.second;
    if (visited[a] == 1 && visited[b] == 0)
      answer.emplace_back(a, b);
    else if (visited[b] == 1 && visited[a] == 0)
      answer.emplace_back(b, a);
  }

  sort(answer.begin(), answer.end());

  cout << answer.size() << endl;
  for (pair<int, int> &e : answer)
  {
    cout << (e.first + 1) << " " << (e.second + 1) << endl;
  }
  return 0;
}
