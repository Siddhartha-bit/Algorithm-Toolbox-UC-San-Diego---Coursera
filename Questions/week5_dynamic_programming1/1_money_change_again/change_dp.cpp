#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int dp[N + 1];
  for (int i = 0; i < N + 1; i++)
    dp[i] = i;

  dp[1] = 1;

  for (int i = 2; i < N + 1; i++)
  {

    if (i - 1 >= 0 && dp[i] > dp[i - 1] + 1)
      dp[i] = dp[i - 1] + 1;

    if (i - 3 >= 0 && dp[i] > dp[i - 3] + 1)
      dp[i] = dp[i - 3] + 1;

    if (i - 4 >= 0 && dp[i] > dp[i - 4] + 1)
      dp[i] = dp[i - 4] + 1;
  }

  cout << dp[N] << endl;

  return 0;
}
