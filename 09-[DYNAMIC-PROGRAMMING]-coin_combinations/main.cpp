#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

/**
 * @brief It uses the iterative divide and conquer technique to calculate the number of times a given sum of
 * money `x` that can be produced using the available `coins`.
 *
 * @param coins The list of coins.
 * @param memo The memoization table.
 * @param n The number of coins.
 * @param x The amount of money.
 */
int solve(vector<int> &coins, vector<int> &memo, int n, int x)
{
  memo[x] = 1; // 1 way to reach 0, not using any coins

  for (int i = x; i >= 0; i--)
  {
    for (int j = 0; j < n; j++)
    {
      int result = i - coins[j];                       // subtract the coin value from the current amount
      if (result >= 0)                                 // if it is valid and still has value to subtract
        memo[result] = (memo[result] + memo[i]) % MOD; // add the number of ways to make the current amount to the number of ways to make the new amount
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
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  vector<int> memo(x);

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  int res = solve(coins, memo, n, x);

  cout << res << endl;

  return 0;
}
