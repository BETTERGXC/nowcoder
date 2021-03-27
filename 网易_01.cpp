/*
      输入两个数字，begin和end
      输出[begin, end]中所有的回文数字，且这个数字是一个回文数字的立方
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isReal(string str) {
      if (str.size() == 1)
            return true;
      int left = 0;
      int right = str.size() - 1;
      while (left < right) {
            if (str[left] == str[right]) {
                  ++left;
                  --right;
            }
            else {
                  return false;
            }
      }
      return true;
}

bool isThreeNum(int num) {
      for (int i = 1; i <= num; i++) {
            if (i * i * i == num) {
                  return true;
            }
            else if (i * i * i > num) {
                  return false;
            }
      }
      return false;
}

int main() {
      int begin;
      int end;
      cin >> begin >> end;
      vector<int> ret;
      for (int i = begin; i < end; i++) {
            if (isReal(to_string(i)) && isThreeNum(i)) {
                  ret.push_back(i);
            }
      }
      cout << "[";
      for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if (i != ret.size() - 1) {
                  cout << ",";
            }
      }
      cout << "]";
      cout << endl;
}