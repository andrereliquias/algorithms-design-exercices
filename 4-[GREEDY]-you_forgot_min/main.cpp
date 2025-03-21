#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Exercise resolution.
 *
 * Given a vector `months` with the size that the flowers grow in each month, check the minimum number of months needed for the flowers to grow `k` size
 *
 * @param months Vector with flower growth for each month.
 * @param k Minimum size the flowers should grow.
 * @return Minimum number of months needed for flowers to grow properly.
 */
int resolution(vector<int> &months, int &k)
{
  if (k == 0)
  {
    return k;
  }

  int sum = 0;
  int res = 0;

  sort(months.begin(), months.end(), greater<int>());

  for (int i = 0; i < 12; i++)
  {
    res++;
    sum += months[i];
    if (sum >= k)
    {
      break;
    }
  }

  if (sum < k)
  {
    return -1;
  }

  return res;
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main()
{
  int k;
  cin >> k;

  vector<int> months(12);

  for (int i = 0; i < 12; i++)
  {
    cin >> months[i];
  }

  int res = resolution(months, k);

  cout << res << endl;

  return 0;
}
