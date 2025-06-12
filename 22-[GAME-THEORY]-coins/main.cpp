#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int grundy[16][16];
int dx[4] = {-2, -2, 1, -1};
int dy[4] = {1, -1, -2, -2};

int mex(unordered_set<int> &c)
{
  int v = 0;
  while (c.count(v) != 0)
    v++;
  return v;
}

int calc(int x, int y)
{
  int &g = grundy[x][y];
  if (g != -1)
    return g;
  unordered_set<int> c;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15)
    {
      c.insert(calc(nx, ny));
    }
  }
  g = mex(c);
  return mex(c);
}

int main()
{
  for (int i = 1; i <= 15; i++)
    for (int j = 1; j <= 15; j++)
      grundy[i][j] = -1;

  for (int i = 1; i <= 15; i++)
    for (int j = 1; j <= 15; j++)
      if (grundy[i][j] == -1)
        calc(i, j);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int k;
    cin >> k;
    int sum = 0;
    for (int j = 0; j < k; j++)
    {
      int x, y;
      cin >> x >> y;
      sum ^= grundy[x][y];
    }
    cout << (sum ? "Primeiro" : "Segundo") << endl;
  }
  return 0;
}
