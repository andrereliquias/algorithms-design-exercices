#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * @brief Given a number `n`, find the minimum number of subtractions needed to reach `0`
 * considering one of its digits.
 *
 * @param n The number to be subtracted.
 * @param memo The memoization table.
 * @return The minimum number of subtractions needed to reach `0`.
 */
int solve(int &n, vector<int> &memo)
{
  memo[n] = 0;
  for (int i = n; i >= 0; i--)
  {
    if (memo[i] == INT_MAX)
      continue;

    string s = to_string(i);
    for (int j = 0; j < s.length(); j++)
    {

      int d = s[j] - '0';

      if (d > 0 && i - d >= 0)
      {
        memo[i - d] = min(memo[i - d], memo[i] + 1);
      }
    }
  }

  return memo[0];
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
  vector<int> memo(n + 1, INT_MAX);

  int res = solve(n, memo);

  cout << res << endl;

  return 0;
}
