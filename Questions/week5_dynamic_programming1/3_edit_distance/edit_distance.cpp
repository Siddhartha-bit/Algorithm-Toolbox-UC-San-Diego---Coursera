#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string s1;
  string s2;

  cin >> s1 >> s2;

  int n1 = s1.length();
  int n2 = s2.length();

  vector<vector<int>> edits(n1 + 1, vector<int>(n2 + 1));

  for (int i = 0; i <= n1; i++)
  {
    for (int j = 0; j <= n2; j++)
    {
      if (j == 0)
        edits[i][j] = i;
      else if (i == 0)
        edits[i][j] = j;
      else
      {
        if (s1[i - 1] == s2[j - 1])
          edits[i][j] = edits[i - 1][j - 1];
        else
          edits[i][j] = 1 + min(edits[i - 1][j], min(edits[i][j - 1], edits[i - 1][j - 1]));
      }
    }
  }

  cout << edits[n1][n2] << endl;

  return 0;
}
