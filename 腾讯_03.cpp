/*
由于业绩优秀，
公司给小Q放了 n 天的假，身为工作狂的小Q打算在在假期中工作、锻炼或者休息。
他有个奇怪的习惯：不会连续两天工作或锻炼。
只有当公司营业时，小Q才能去工作，只有当健身房营业时，小Q才能去健身，
小Q一天只能干一件事。给出假期中公司，健身房的营业情况，
求小Q最少需要休息几天。
*/ 

/*
思路：动态规划
dp[len+1][3]   
	dp数组的含义
	dp[i][0]  第i天休息，从第 0 天到第 i 天最多休息的天数 
	dp[i][1]  第i天锻炼，从第 0 天到第 i 天最多休息的天数 
	dp[i][2]  第i天工作，从第 0 天到第 i 天最多休息的天数 
需要注意的是，dp[i][j]表示的只是一种状态，表示的只是当天在干嘛 
*/ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
      int n;
      while (cin >> n) {
            vector<int> gym(n);
            vector<int> work(n);
            for (int i = 0; i < n; ++i)
                  cin >> work[i];
            for (int i = 0; i < n; ++i)
                  cin >> gym[i];
            vector<vector<int>> dp(n + 1, vector<int>(3)); // 0是休息，1是锻炼，2是工作
            dp[0][0] = dp[0][1] = dp[0][2] = 0;
            for (int i = 1; i <= n; ++i) {
                  if (gym[i - 1] == 1) {
                        // 可以锻炼
                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
                  }
                  if (work[i - 1] == 1) {
                        // 可以工作
                        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
                  }
                  dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            }
            int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
            cout << res << endl;
      }
      return 0;
}
