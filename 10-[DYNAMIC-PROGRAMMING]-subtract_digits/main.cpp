#include <iostream>
#include <vector>

using namespace std;

int solve(int &n, vector<int> &memo)
{
  memo[n] = 0;
  int i = n;

  while (i != 0)
  {
    string s = to_string(i);
    char maxDigitC = *std::max_element(s.begin(), s.end());
    int maxDigit = maxDigitC - '0';
    int result = i - maxDigit;

    if (result >= 0)
      memo[result] = (memo[result] + memo[i]) + 1;

    i = result;
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
  vector<int> memo(n);

  int res = solve(n, memo);

  cout << res << endl;

  return 0;
}
