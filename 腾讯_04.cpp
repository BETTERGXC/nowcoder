/*
СQ�ڽ���һ��������Ϸ,�ⳡ��Ϸ��ʤ���ؼ��������ܷ�������һ������ΪL�ĺӵ�,
�����Կ�����[0,L]��һ�����ᡣ
������Ϸ������n�������ṩ��Ұ�ĵ���?��������,
��i�����������ܹ���������[xi,yi]��
����СQ��֪�������ü������������Ϳ��Ը������κӵ��� 
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
