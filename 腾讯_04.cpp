/*
小Q在进行一场竞技游戏,这场游戏的胜负关键就在于能否能争夺一条长度为L的河道,
即可以看作是[0,L]的一条数轴。
这款竞技游戏当中有n个可以提供视野的道具?真视守卫,
第i个真视守卫能够覆盖区间[xi,yi]。
现在小Q想知道至少用几个真视守卫就可以覆盖整段河道。 
*/ 

#include <iostream>
#include <vector>
#include <algorit
using namespace std;

bool cmp(vector<int>& arr1, vector<int>& arr2) {
      return arr1[0] < arr2[0] || (arr1[0] == arr2[0] && arr1[1] > arr2[1]);
}

int main() {
      int n, L;
      cin >> n >> L;
      vector<vector<int>> input(n, vector<int>(2));
      for (int i = 0; i < n; i++) {
            cin >> input[i][0] >> input[i][1];
      }
      sort(input.begin(), input.end(), cmp);
      int last = 0;
      int pre = 0;
      int ans = 0;
      int i = 0;
      while (i < n) {
            while (i < n && input[i][0] <= pre) {
                  last = max(last, input[i][1]);
                  ++i;
            }
            ans++;
            pre = last;
            if (i < n && input[i][0] > pre) {
                  ans = -1;
                  break;
            }
            if (last >= L)
                  break;
      }
      if (ans == -1 || last < L)
            cout << -1 << endl;
      else
            cout << ans << endl;
}
