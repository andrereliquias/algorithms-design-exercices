#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Given two arrays `a` and `b`, find the maximum subarray sum
 *        that crosses the middle of the two arrays.
 *
 * @param a The first array.
 * @param b The second array.
 * @return The maximum subarray sum that crosses the middle of the two arrays.
 */
int crossedSubarraySum(vector<int> &a, vector<int> &b)
{
  int sumA = 0, sumB = 0;
  int temp = 0;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    temp += a[i];
    sumA = max(sumA, temp); // best sum from A
  }
  temp = 0;
  for (int i = 0; i < b.size(); i++)
  {
    temp += b[i];
    sumB = max(sumB, temp); // best sum from B
  }
  return sumA + sumB;
}

/**
 * @brief Given an arraty `l`, find the maximum subarray sum.
 *
 * @param l The input array.
 * @return The maximum subarray sum.
 */
int subarraySum(vector<int> &l)
{
  int len = l.size();
  if (len == 1)
    return l[0]; // the element it self

  int mid = len / 2;

  vector<int> a(l.begin(), l.begin() + mid);
  vector<int> b(l.begin() + mid, l.end());

  int ra = subarraySum(a);
  int rb = subarraySum(b);
  int r = crossedSubarraySum(a, b);

  return max({r, ra, rb});
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<int> l(n);

  for (int i = 0; i < n; ++i)
    cin >> l[i];

  int res = subarraySum(l);
  cout << res << endl;

  return 0;
}
