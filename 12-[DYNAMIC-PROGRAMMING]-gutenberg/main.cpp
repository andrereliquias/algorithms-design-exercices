#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Find the maximum number of book p with pages pg you can buy with x amount of money
 *
 * @param p The price of the books.
 * @param pg The pages of the books.
 * @param memo The memoization array.
 * @param x The amount of money you have.
 * @param n The number of books.
 * @return The maximum number of pages you can buy.
 */
int solve(vector<int> &p, vector<int> &pg, vector<int> &memo, int x, int n)
{
  for (int i = 0; i < n; i++)
  {
    int price = p[i];
    int pages = pg[i];
    for (int b = x; b >= price; b--)
    {
      memo[b] = max(memo[b], memo[b - price] + pages);
    }
  }

  return memo[x];
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

  vector<int> p(n);
  vector<int> pg(n);
  vector<int> memo(x + 1, 0);

  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> pg[i];

  int res = solve(p, pg, memo, x, n);
  cout << res << endl;

  return 0;
}
