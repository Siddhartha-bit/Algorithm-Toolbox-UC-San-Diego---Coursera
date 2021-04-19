#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int W, n;
  cin >> W >> n;

  int input[n];
  for (int i = 0; i < n; i++)
    cin >> input[i];

  vector<vector<int>> maxWeight(n + 1, vector<int>(W + 1));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (input[i - 1] > j)
        maxWeight[i][j] = maxWeight[i - 1][j];
      else
        maxWeight[i][j] = max(maxWeight[i - 1][j - input[i - 1]] + input[i - 1], maxWeight[i - 1][j]);
      // cout << maxWeight[i][j] << " ";
    }
    // cout << endl;
  }

  cout << maxWeight[n][W];

  return 0;
}
