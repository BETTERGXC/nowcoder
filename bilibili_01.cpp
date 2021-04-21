/*
	��һ�� W*H �ķ�Χ����N ����������м���AOE���ܣ����ܵ����Χ������R
	��ÿ��AOE�����ܴ򵽶��ٸ�����
	����
	��һ�� N W H R
	�������� N ��  ÿһ��  ��ʾ ����id--K ����X����--x  ����Y����--y
	����M AOE���ܵĸ���
	M��  ÿһ��  AOE���ܵ� X����  Y����  ��Χr
	
	���һ��AOE���ܴﵽ�����ˣ�����ﵽ����ĸ���  ��߸��򵽵Ĺ����id
	
	
	����
	2 5 5 3
	1 1 2
	2 2 2
	1
	3 3 3 
	
	���
	2 1 2 
*/ 

#include <iostream>
#include <vector>
using namespace std;

int main() {
      int N, W, H, R;
      cin >> N >> W >> H >> R;
      vector<vector<double>> input(N, vector<double>(3, 0));
      for (int i = 0; i < N; i++) {
            cin >> input[i][0] >> input[i][1] >> input[i][2];
      }
      int M;
      cin >> M;
      vector<vector<double>> aoe(M, vector<double>(3, 0));
      for (int i = 0; i < M; i++) {
            cin >> aoe[i][0] >> aoe[i][1] >> aoe[i][2];
      }
      vector<vector<int>> res;
      for (int i = 0; i < M; i++) {
            vector<int>tmp(1, 0);
            for (int j = 0; j < N; j++) {
                  if (sqrt(pow((input[j][1] - aoe[i][0]), 2) + pow((input[j][2] - aoe[i][1]), 2)) < aoe[i][2]) {
                        tmp[0]++;
                        tmp.push_back(input[j][0]);
                  }
            }
            if (tmp[0] > 0) {
                  res.push_back(tmp);
            }
      }
      for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                  cout << res[i][j] << ' ';
            }
            cout << endl;
      }
      return 0;
}
