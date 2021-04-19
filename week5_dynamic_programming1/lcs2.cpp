#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n1, n2;

  cin >> n1;
  vector<int> array1(n1);
  for (int i = 0; i < n1; i++)
    cin >> array1[i];

  cin >> n2;
  vector<int> array2(n2);
  for (int i = 0; i < n2; i++)
    cin >> array2[i];

  vector<vector<int>> edits(n1 + 1, vector<int>(n2 + 1));

  for (int i = 1; i <= n1; i++)
  {
    for (int j = 1; j <= n2; j++)
    {
      if (array1[i - 1] == array2[j - 1])
        edits[i][j] = 1 + edits[i - 1][j - 1];
      else
        edits[i][j] = max(edits[i - 1][j], edits[i][j - 1]);
    }
  }

  cout << edits[n1][n2] << endl;

  return 0;
}
