#include <iostream>
#include <vector>
#include <set>

using namespace std;

int mex(set<int> &c)
{
  int v = 0;
  while (c.count(v) != 0)
    v++;
  return v;
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  vector<int> totals(t, 0);

  int max = -1;
  for (int i = 0; i < t; i++)
  {
    cin >> totals[i];
    if (max < totals[i])
      max = totals[i];
  }

  vector<bool> grundy(max + 1, -1);
  grundy[0] = 0;

  vector<int> moves = {2, 3, 5};

  for (int n = 1; n <= max; n++)
  {
    set<int> conj;
    for (int k = 0; k < 3; k++)
    {
      int m = moves[k];
      if (n - m >= 0)
      {
        conj.insert(grundy[n - m]);
      }
    }
    grundy[n] = mex(conj);
  }

  for (int n : totals)
  {
    cout << (grundy[n] ? "Tico" : "Teco") << endl;
  }
  return 0;
}
