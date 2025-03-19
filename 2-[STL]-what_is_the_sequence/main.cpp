#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Compare
{
public:
  bool operator()(vector<int> a, vector<int> b)
  {
    if (a[0] != b[0])
      return a[0] > b[0]; // less time
    return a[1] > b[1];   // tiebreaked by ID
  }
};

/**
 * @brief Exercise resolution.
 *
 * Given a priority queue `pq`, it returns the result of the user's query based on the next incremented time.
 * In the case of a tie, it considers the one with the lowest ID
 *
 * @return Result.
 */
void resolution(priority_queue<vector<int>, vector<vector<int> >, Compare> &pq)
{
  vector<int> p = pq.top();
  pq.pop();

  vector<int> p2 = pq.top();

  if (p[0] == p2[0] && p2[1] < p[1])
  {
    pq.pop();
    pq.push(p);
    p = p2;
  }

  cout << p[1] << endl;
  p[0] = p[0] + p[2];

  pq.push(p);
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main()
{
  string _;
  int n, k;
  cin >> n;

  priority_queue<vector<int>, vector<vector<int> >, Compare> pq;
  for (int i = 0; i < n; i++)
  {
    vector<int> v(3);
    cin >> _ >> v[1] >> v[0];
    v[2] = v[0];
    pq.push(v);
  }

  cin >> k;

  for (int i = 0; i < k; i++)
  {
    resolution(pq);
  }

  return 0;
}
