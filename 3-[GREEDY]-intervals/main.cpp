#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Exercise resolution.
 * 
 * Given a `pairs` vector, check the number of intervals resulting from merging overlapping intervals into a single interval.
 * 
 * @param pairs Vector of pairs
 * @param n Number of pairs
 * @return Number of intervals
 */
int resolution(vector<pair<int, int> > &pairs, int &n)
{
  int count = 1;

  sort(pairs.begin(), pairs.end());

  int biggest = pairs[0].second;
  for (int i = 0; i < n; i++)
  {
    if (pairs[i].second > biggest)
    {
      biggest = pairs[i].second;
    }

    if (pairs[i + 1].first > biggest)
    {
      count++;
    }
  }

  return count;
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main()
{
  int n;
  cin >> n;

  vector<pair<int, int> > pairs(n);

  for (int i = 0; i < n; i++)
  {
    int s, e;
    cin >> s >> e;
    pairs[i] = make_pair(s, e);
  }

  int res = resolution(pairs, n);

  cout << res << endl;

  return 0;
}
