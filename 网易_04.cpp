/*
	M个小朋友围成一个圈玩猜拳游戏。每个小朋友只会出石头剪子布
	1）当前这个小朋友会和顺时针方向下一个小朋友猜拳
	2）如果当前这个小朋友胜利，则被挑战得相邻得这个小朋友会出圈淘汰，当前这个小朋友继续执行 1
	3）如果当前这个小盆骨失败，则该小朋友出圈淘汰，由被挑战得小朋友成为新得小朋友
	4）平手无人淘汰，下一个小朋友开始
	R石头 S剪刀 C布 
*/ 

/*
	测试用例：
	3
	5 5
	RRRRR
	3 2
	RSC
	3 1
	RRC 
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
      int T;
      cin >> T;
      while (T--) {
            int N, M;
            cin >> N >> M;
            string input;
            cin >> input;
            vector<int> count(input.size(), 1);
            for (int i = 1; i < input.size(); i++) {
                  if (input[i] == input[i - 1]) {
                        count[i] = count[i - 1] + 1;
                  }
            }
            int index = 0;
            for (int i = 1; i < count.size(); i++) {
                  if (count[i] > count[index]) {
                        index = i;
                  }
            }
            index = count[index] - index - 1;
            while (M--) {
                  int flag = 0;
                  if (index + 1 < input.size()) {
                        if ((input[index] == 'R' && input[index + 1] == 'S') || (input[index] == 'S' && input[index + 1] == 'C') ||
                              (input[index] == 'C' && input[index+1] == 'R')) {
                              input.erase(input.begin() + index);
                              flag = 1;
                        }
                  }
                  else {
                        if ((input[index] == 'R' && input[0] == 'S') || (input[index] == 'S' && input[0] == 'C') ||
                              (input[index] == 'C' && input[0] == 'R')) {
                              input.erase(input.begin());
                              flag = 1;
                        }
                  }
                  
                  if (flag == 0) {
                        if (index >= input.size()) {
                              index = 0;
                        }
                        else {
                              index++;
                        }
                  }
            }
            cout << input.size() << endl;
      }
}
