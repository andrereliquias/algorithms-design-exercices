#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    string c = "Case " + std::to_string(i + 1) + ": ";

    int n;
    cin >> n;

    unordered_map<string, int> umap(n);
    for (int j = 0; j < n; j++)
    {
      string theme;
      int days;
      cin >> theme >> days;
      umap[theme] = days;
    }

    int d;
    string task;
    cin >> d >> task;
    unordered_map<string, int>::iterator search = umap.find(task);

    if (search != umap.end())
    {
      if (search->second <= d)
      {
        cout << c + "Ufa!" << endl;
      }
      else if (search->second > d && search->second <= d + 5)
      {
        cout << c + "Atrasado" << endl;
      }
      else
      {
        cout << c + "Deu ruim! Va trabalhar" << endl;
      }
    }
    else
    {
      cout << c + "Deu ruim! Va trabalhar" << endl;
    }
  }

  return 0;
}
