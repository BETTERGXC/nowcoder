/*
	在一个 W*H 的范围内有N 个怪物。现在有几个AOE技能，技能的最大范围不超过R
	问每个AOE技能能打到多少个怪物
	输入
	第一行 N W H R
	接下来的 N 行  每一行  表示 怪物id--K 怪物X坐标--x  怪物Y坐标--y
	输入M AOE技能的个数
	M行  每一行  AOE技能的 X坐标  Y坐标  范围r
	
	如果一个AOE技能达到怪物了，输出达到怪物的个数  后边跟打到的怪物的id
	
	
	例如
	2 5 5 3
	1 1 2
	2 2 2
	1
	3 3 3 
	
	输出
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
