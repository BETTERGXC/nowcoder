/*
	股票会在先涨几天后跌几天，涨的几天内，每天涨的都一样
	跌的几天里，每天跌的一样。涨完就跌，跌完就涨，循环往复。
	给一个目标值，问几天能达到，能达到输出几天，达不到输出 -1 
*/ 

#include <iostream>
using namespace std;

int main() {
      int T;
      cin >> T;
      while (T--) {
            int M, N, X, Y, P;
            cin >> M >> N >> X >> Y >> P;
            // 分两种情况
            // 1. 连续几天的增长大于连续几天的减少 —— 最终会达到目标值
            // 2. 连续几天的增长小于连续几天的减少 —— 要么在一开始的增长就达到目标值，要么永远达不到
            
            P = P - 100000;
            int count = 0;  // 累计最后多少天可以达到目标值
            int flag;    // 判断增长是否大于减少
            if (M * X > N * Y) {
                  flag = 1;
            }
            else{
                  flag = 0;
            }

            //增长大于减少的，只需要算最终多少天即可
            if (flag == 1) {
                  while (P > 0) {
                        int m = M;
                        int n = N;
                        int help = 0;
                        P -= m * X;
                        count += m;
                        if (P <= 0) {
                              while (P <= 0) {
                                    P += X;
                                    count--;
                              }
                              P -= X;
                              count++;
                        }
                        if (P > 0) {
                              P += n * Y;
                              count += n;
                        }
                  }
                  cout << count << endl;
            }
            // 增长小于减少
            else {
                  int m = M;
                  // 判断能否在增长的几天内达到目标值
                  int help = 0;
                  while (m > 0) {
                        P -= X;
                        m--;
                        count++;
                        if (P <= 0) {
                              help = 1;
                              break;
                        }
                  }
                  if (help == 1) {
                        cout << count << endl;
                  }
                  else {
                        cout << -1 << endl;
                  }
            }
      }
}
