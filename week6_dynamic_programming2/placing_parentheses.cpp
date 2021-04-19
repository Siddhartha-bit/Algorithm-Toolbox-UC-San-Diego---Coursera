#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  cin >> s;

  vector<int> digits;
  vector<char> oper;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '*' || s[i] == '+' || s[i] == '-')
      oper.push_back(s[i]);
    else
      digits.push_back(s[i] - '0');
  }

  long long len = digits.size();
  long long minimum[len][len];
  long long maximum[len][len];

  for (int i = 0; i < len; i++)
  {

    for (int j = 0; j < len - i; j++)
    {

      int k = j + i;

      if (k == j)
      {
        minimum[j][k] = digits[k];
        maximum[j][k] = digits[k];
      }
      else
      {
        long long min_temp = INT_MAX;
        long long max_temp = INT_MIN;

        for (int l = j; l < k; l++)
        {
          long long a, b, c, d;

          if (oper[l] == '*')
          {
            a = minimum[j][l] * minimum[l + 1][k];
            b = minimum[j][l] * maximum[l + 1][k];
            c = maximum[j][l] * minimum[l + 1][k];
            d = maximum[j][l] * maximum[l + 1][k];
          }
          else if (oper[l] == '+')
          {
            a = minimum[j][l] + minimum[l + 1][k];
            b = minimum[j][l] + maximum[l + 1][k];
            c = maximum[j][l] + minimum[l + 1][k];
            d = maximum[j][l] + maximum[l + 1][k];
          }
          else if (oper[l] == '-')
          {
            a = minimum[j][l] - minimum[l + 1][k];
            b = minimum[j][l] - maximum[l + 1][k];
            c = maximum[j][l] - minimum[l + 1][k];
            d = maximum[j][l] - maximum[l + 1][k];
          }

          min_temp = min(min_temp, min(a, min(b, min(c, d))));
          max_temp = max(max_temp, max(a, max(b, max(c, d))));

          minimum[j][k] = min_temp;
          maximum[j][k] = max_temp;
        }
      }
    }
  }

  cout << maximum[0][len - 1];

  return 0;
}
