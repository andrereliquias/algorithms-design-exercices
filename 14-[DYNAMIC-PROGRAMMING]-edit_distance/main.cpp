#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief Find the minimum number of edits needed to change one word into another (edit distance by vladimir levenshtein)
 *
 * @param first The first string.
 * @param second The second string.
 * @param memo The memoization table.
 *
 * @return The minimum number of edits needed to change one word into another.
 */
int solve(string &first, string &second, vector<vector<int>> &memo)
{

  // base cases
  for (int i = 0; i <= first.size(); i++)
    memo[i][0] = i;
  for (int j = 0; j <= second.size(); j++)
    memo[0][j] = j;

  for (int i = 1; i <= first.size(); i++)
  {
    for (int j = 1; j <= second.size(); j++)
    {
      int cost = 0;
      if (first[i - 1] != second[j - 1])
      {
        cost = 1;
      }

      memo[i][j] = min({memo[i - 1][j] + 1,          // remove from first
                        memo[i][j - 1] + 1,          // add to second
                        memo[i - 1][j - 1] + cost}); // replace with cost 1 or 0 (if equal)
    }
  }

  return memo[first.size()][second.size()];
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
  string first, second;
  cin >> first >> second;

  vector<vector<int>> memo(first.size() + 1, vector<int>(second.size() + 1, 0));

  int res = solve(first, second, memo);
  cout << res << endl;

  return 0;
}
