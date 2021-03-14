/*
����ҵ�����㣬
��˾��СQ���� n ��ļ٣���Ϊ�������СQ�������ڼ����й���������������Ϣ��
���и���ֵ�ϰ�ߣ������������칤���������
ֻ�е���˾Ӫҵʱ��СQ����ȥ������ֻ�е�����Ӫҵʱ��СQ����ȥ����
СQһ��ֻ�ܸ�һ���¡����������й�˾��������Ӫҵ�����
��СQ������Ҫ��Ϣ���졣
*/ 

/*
˼·����̬�滮
dp[len+1][3]   
	dp����ĺ���
	dp[i][0]  ��i����Ϣ���ӵ� 0 �쵽�� i �������Ϣ������ 
	dp[i][1]  ��i��������ӵ� 0 �쵽�� i �������Ϣ������ 
	dp[i][2]  ��i�칤�����ӵ� 0 �쵽�� i �������Ϣ������ 
��Ҫע����ǣ�dp[i][j]��ʾ��ֻ��һ��״̬����ʾ��ֻ�ǵ����ڸ��� 
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
            vector<vector<int>> dp(n + 1, vector<int>(3)); // 0����Ϣ��1�Ƕ�����2�ǹ���
            dp[0][0] = dp[0][1] = dp[0][2] = 0;
            for (int i = 1; i <= n; ++i) {
                  if (gym[i - 1] == 1) {
                        // ���Զ���
                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
                  }
                  if (work[i - 1] == 1) {
                        // ���Թ���
                        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
                  }
                  dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            }
            int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
            cout << res << endl;
      }
      return 0;
}
