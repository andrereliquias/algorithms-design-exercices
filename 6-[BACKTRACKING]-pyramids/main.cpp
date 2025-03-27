#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * @brief Exercise resolution.
 *
 * Given a `p` vector with the number of stones carried by the ith robot, check the number mission values `acc` for all possible subsets of robots that can be chosen in a mission
 *
 * @param p Vector with the number of stones carried by the ith robot.
 * @param n Number of robots.
 * @param s Set with the possible sums.
 * @param count Current robot.
 * @param acc Current sum.
 * @return void
 */
void resolution(vector<int> &p, int &n, set<int> &s, int count, int acc)
{
  if (count == n)
  {
    if (acc != 0)
      s.insert(acc);
    return;
  }

  int last = p.back();
  p.pop_back();
  resolution(p, n, s, count + 1, acc);
  resolution(p, n, s, count + 1, acc + last);
  p.push_back(last);
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

  vector<int> p(n);
  set<int> s;

  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }

  resolution(p, n, s, 0, 0);

  cout << s.size();

  return 0;
}
