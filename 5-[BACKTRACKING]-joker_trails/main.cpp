#include <iostream>
#define SIZE 9

bool marked[SIZE][SIZE];

char xMoves[4] = {0, 0, -1, 1};
char yMoves[4] = {1, -1, 0, 0};

using namespace std;

/**
 * @brief Check if the position is valid.
 *
 * @param v The value to check.
 * @return `true` if the value is valid, `false` otherwise.
 */
bool valid(char v)
{
  return (v >= 0) && (v < SIZE);
}

/**
 * @brief Count the number of valid paths.
 *
 * This function uses backtracking to explore all possible paths
 * from the starting position (0, 6) to the end of the string (0, 0).
 *
 * @param n The current index in the string.
 * @param x The current x-coordinate.
 * @param y The current y-coordinate.
 * @param countValidPaths The count of valid paths found so far.
 * @param t The input string representing the path.
 */
void resolution(int n, int x, int y, int &countValidPaths, string t)
{
  if (n == t.size())
  {
    if (x == 1 && y == 1)
    {
      countValidPaths += 1;
    }
    return;
  }

  char currentDirection = t[n];
  char newX, newY;

  if (currentDirection == '?')
  {
    // test all movement possibilities
    for (int i = 0; i < 4; i++)
    {
      newX = x + xMoves[i];
      newY = y + yMoves[i];
      if (valid(newX) && valid(newY) && !marked[newX][newY])
      {
        marked[newX][newY] = true;
        resolution(n + 1, newX, newY, countValidPaths, t);
        marked[newX][newY] = false;
      }
    }
  }
  else
  {
    if (currentDirection == 'U') // up
    {
      newX = x;
      newY = y + 1;
    }
    else if (currentDirection == 'D') // down
    {
      newX = x;
      newY = y - 1;
    }
    else if (currentDirection == 'L') // left
    {
      newX = x - 1;
      newY = y;
    }
    else if (currentDirection == 'R') // rigth
    {
      newX = x + 1;
      newY = y;
    }

    if (valid(newX) && valid(newY) && !marked[newX][newY])
    {
      marked[newX][newY] = true;
      resolution(n + 1, newX, newY, countValidPaths, t);
      marked[newX][newY] = false;
    }
  }
}

/**
 * @brief Main function.
 *
 * @return `0` if sucess.
 */
int main()
{

  int i, j;
  char c;
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
    {
      if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1)
        marked[i][j] = true;
      else
        marked[i][j] = false;
    }

  string t;
  cin >> t;

  int countValidPaths = 0;

  int startX = 0 + 1;
  int startY = 6 + 1;
  marked[startX][startY] = true;
  resolution(0, startX, startY, countValidPaths, t);

  cout << countValidPaths << endl;

  return 0;
}
