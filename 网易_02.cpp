/*
	��Ʊ�������Ǽ��������죬�ǵļ����ڣ�ÿ���ǵĶ�һ��
	���ļ����ÿ�����һ��������͵���������ǣ�ѭ��������
	��һ��Ŀ��ֵ���ʼ����ܴﵽ���ܴﵽ������죬�ﲻ����� -1 
*/ 

#include <iostream>
using namespace std;

int main() {
      int T;
      cin >> T;
      while (T--) {
            int M, N, X, Y, P;
            cin >> M >> N >> X >> Y >> P;
            // ���������
            // 1. �������������������������ļ��� ���� ���ջ�ﵽĿ��ֵ
            // 2. �������������С����������ļ��� ���� Ҫô��һ��ʼ�������ʹﵽĿ��ֵ��Ҫô��Զ�ﲻ��
            
            P = P - 100000;
            int count = 0;  // �ۼ�����������ԴﵽĿ��ֵ
            int flag;    // �ж������Ƿ���ڼ���
            if (M * X > N * Y) {
                  flag = 1;
            }
            else{
                  flag = 0;
            }

            //�������ڼ��ٵģ�ֻ��Ҫ�����ն����켴��
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
            // ����С�ڼ���
            else {
                  int m = M;
                  // �ж��ܷ��������ļ����ڴﵽĿ��ֵ
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
