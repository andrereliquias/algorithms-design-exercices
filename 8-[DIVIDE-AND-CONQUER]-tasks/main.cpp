#include <iostream>
#include <vector>

using namespace std;

double error = 0.001;

/**
 * @brief Sum to calculate the number of workers needed to complete the tasks in the maximum `mid` time.
 *
 * @param t Vector with the time of each task.
 * @param mid Maximum time a worker can have when grouping tasks
 */
double f(vector<int> &t, double &mid)
{
  int sum = 0;
  int count = 1; // at least 1 worker

  for (int i = 0; i < t.size(); i++)
  {
    if (sum + t[i] > mid)
    {
      count++;
      sum = t[i];
    }
    else
    {
      sum += t[i];
    }
  }

  return count;
}

/**
 * @brief given the time of each task in the vector `t`, the total number of workers `k`
 * and the interval between the largest task `inf` and the sum of all tasks `sup` calculates
 * the maximum load a worker will have.
 *
 * @param t Vector with the time of each task.
 * @param k Number of workers.
 * @param inf Time of largest task.
 * @param sup Time of all the tasks.
 *
 * @return Maximum amount of time a worker will have.
 */
int divideAndConquer(vector<int> &t, int &k, int &inf, int &sup)
{

  while (sup - inf > error)
  {
    double mid = (inf + sup) / 2.0;
    int result = f(t, mid);
    if (result > k)  // if need more workers than provided
      inf = mid + 1; // update inf with mid + 1
    else             // if a worker is still available
      sup = mid;     // update sup with mid
  }

  return inf;
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
  int i, k;
  cin >> i;
  vector<int> t(i);

  int sumValue = 0;
  int maxValue = 0;
  for (int j = 0; j < i; ++j)
  {
    cin >> t[j];
    sumValue += t[j];
    if (t[j] > maxValue)
    {
      maxValue = t[j];
    }
  }

  cin >> k;

  int res = divideAndConquer(t, k, maxValue, sumValue);
  cout << res << endl;

  return 0;
}
