#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int dp[N + 1];
  for (int i = 0; i < N + 1; i++)
    dp[i] = N;

  dp[1] = 0;

  for (int i = 2; i < N + 1; i++)
  {

    if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
      dp[i] = dp[i / 2] + 1;

    if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
      dp[i] = dp[i / 3] + 1;

    if (dp[i] > dp[i - 1] + 1)
      dp[i] = dp[i - 1] + 1;
  }

  cout << dp[N] << endl;

  vector<int> seq;

  while (N > 1)
  {
    seq.push_back(N);

    if (dp[N - 1] == dp[N] - 1)
      N = N - 1;

    else if (N % 2 == 0 &&
             dp[N / 2] == dp[N] - 1)
      N = N / 2;

    else
      N = N / 3;
  }
  seq.push_back(1);

  for (int i = seq.size() - 1; i >= 0; i--)
    cout << seq[i] << " ";

  cout << endl;

  return 0;
}
