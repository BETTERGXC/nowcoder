/*
小Q在周末的时候和他的小伙伴来到大城市逛街，
一条步行街上有很多高楼，共有n座高楼排成一行。
小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，
所以他想知道他在每栋楼的位置处能看到多少栋楼呢？
（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住） 
*/

// 示例 
/*
输入 
6
5 3 8 3 2 5

输出
3 3 5 4 4 4 
*/

// 代码运行结果  ：超时，时间复杂度过大 

#include <iostream>
#include <vector>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> input(n);
      vector<int> output(n);
      for (int i = 0; i < n; i++) {
            cin >> input[i];
      }
      for (int i = 0; i < n; i++) {
            int maxleft = -1;
            int sumleft = 0;
            int maxright = -1;
            int sumright = 0;
            for (int j = i; j < n-1; j++) {
                  if (maxright < input[j + 1]) {
                        sumright++;
                        maxright = input[j + 1];
                  }
            }
            for (int j = i; j > 0; j--) {
                  if (maxleft < input[j - 1]) {
                        sumleft++;
                        maxleft = input[j - 1];
                  }
            }
            output[i] = sumleft + sumright + 1;
      }
      for (int i = 0; i < n; i++) {
            cout << output[i] << " ";
      }
      cout << endl;
}


//  大佬的解法
#include <iostream>
#include <string>
using namespace std;

int main() {
      string s;
      cin >> s;
      int i = 0;
      while (i < s.length()) {
            if (s[i] == ']') {
                  int j = i;//j用来向前寻找与]相匹配的[
                  int k = 0;//k用来记录'|'所在位置
                  while (s[j] != '[') {
                        if (s[j] == '|')
                              k = j;
                        j--;
                  }
                  int len = stoi(s.substr(j + 1, k - j));
                  string s1 = s.substr(k + 1, i - k - 1);
                  string s2;
                  for (int si = 0; si < len; si++) {//将识别到的括号内容进行解码
                        s2 += s1;
                  }
                  s = s.replace(j, i - j + 1, s2);
                  i = j;//替换后i所指向的内容变化，从替换部分的头开始再寻找
            }
            i++;
      }
      cout << s << endl;
}
 
