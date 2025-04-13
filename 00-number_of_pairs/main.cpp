#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Exercise resolution.
 *
 * Calculates the number of pairs (vi, vj) of elements in the `nums` vector whose sum is `s`.
 *
 * @return Result.
 */
int resolution(int n, int s, vector<int> nums)
{
  int count = 0;
  unordered_map<int, int> umap;

  for (int i = 0; i < n; i++)
  {
    int remain = s - nums[i];
    unordered_map<int, int>::iterator search = umap.find(remain);

    if (search != umap.end())
      count += search->second;

    umap[nums[i]]++;
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
  int n, s;
  cin >> n >> s;

  vector<int> nums(n);

  for (int i = 0; i < n; ++i)
    cin >> nums[i];

  int res = resolution(n, s, nums);

  cout << res << endl;

  return 0;
}
