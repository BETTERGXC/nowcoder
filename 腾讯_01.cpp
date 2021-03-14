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


// 大佬的答案   ： 单调栈 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a, b;
stack<int> st1, st2;
  
int main() {
    int n, x[100001];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i];
      
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        a.push_back(st1.size());
        b.push_back(st2.size());
          
        while (!st1.empty() && st1.top() <= x[i]) st1.pop();
        while (!st2.empty() && st2.top() <= x[j]) st2.pop();
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1<< " ";
    return 0;
}

