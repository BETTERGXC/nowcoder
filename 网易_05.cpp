/*
	输入包含多组数组，每一行第一个是一个整数N， 表示一共有多少个闯关成功得记录。随后是N行记录，每行记录包括两个整数
	id  s（分数）
	如果当前id得分数等于排行榜中得中位数，发放一次奖品，问最终发放几次奖品 
	
	
	例如：
	1
	5
	1 1
	2 2
	3 3
	4 2 
	1 2
	输出 2
	 
*/ 


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

double middle(map<int, int>& _map) {
      vector<int> help;
      for (auto& e : _map) {
            help.push_back(e.second);
      }
      sort(help.begin(), help.end());
      if (help.size() % 2 == 0) {
            return (help[help.size() / 2 - 1] + help[help.size() / 2]) / 2;
      }
      else {
            return help[help.size() / 2];
      }
}
int main() {
      int T;
      cin >> T;
      while (T--) {
            int N;
            cin >> N;
            map<int, bool> used;
            vector<vector<int>> input(N, vector<int>(2, 0));
            for (int i = 0; i < N; i++) {
                  cin >> input[i][0] >> input[i][1];
                  used[input[i][0]] = false;
            }
            int count = 0;      
            
            map<int,  int> _map;
            for (int i = 0; i < N; i++) {
                  _map.insert(pair<int, int>(input[i][0], input[i][1]));
                  if (_map[input[i][0]] == middle(_map) && used[input[i][0]] == false) {
                        count++;
                        used[input[i][0]] = true;
                  }
            }
            cout << count << endl;
      }
}
