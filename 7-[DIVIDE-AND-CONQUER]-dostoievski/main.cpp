#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v)
{
  for (auto i : v)
    std::cout << i << " ";
  std::cout  << std::endl;
}

int mergeAndCount(std::vector<int> &a, std::vector<int> &b, std::vector<int> &l)
{
  std::cout << "mergeAndCount" << std::endl;
  std::cout << "a: ";
  printVector(a);
  std::cout << "b: ";
  printVector(b);

  int count = 0;
  int i = 0, j = 0;
  std::vector<int> sorted;

  while (i < a.size() && j < b.size())
  {
    bool isLess = a[i] <= b[j];
    std::cout << "a[i]: " << a[i] << " b[j]: " << b[j] << std::endl;
    std::cout << "isLess: " << isLess << " " <<  std::endl;

    if (isLess)
    {
      sorted.push_back(a[i]);
      i++;
    }
    else
    {
      count = count + (a.size() - i);
      sorted.push_back(b[j]);
      j++;
    }
  }

  while (i < a.size())
  {
    sorted.push_back(a[i]);
    i++;
  }
  while (j < b.size())
  {
    sorted.push_back(b[j]);
    j++;
  }

  std::cout << "sorted: " << std::endl;
  printVector(sorted);
  for (int i = 0; i < sorted.size(); i++)
  {
    l[i] = sorted[i];
  }
  
  return count;
}

int sortAndCount(std::vector<int> &l)
{
  int len = l.size();
  if (len == 1)
    return 0;

  int mid = len / 2;
  std::cout << "mid: " << mid << std::endl;

  std::vector<int> a(l.begin(), l.begin() + mid);
  std::vector<int> b(l.begin() + mid, l.end());

  int ra = sortAndCount(a);
  int rb = sortAndCount(b);
  int r = mergeAndCount(a, b, l);

  return ra + rb + r;
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  std::vector<int> l(n);

  for (int i = 0; i < n; ++i)
    std::cin >> l[i];

  int res = sortAndCount(l);
  std::cout << res << std::endl;
  printVector(l);

  return 0;
}
