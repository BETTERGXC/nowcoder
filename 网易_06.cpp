/*
	一个二维数组，根据其中某一列的大小进行排序改变几行的的顺序
	输入：
	M N T
	输入 M * N 的二维数组
	输入T行要改变的数  
	每行6个数
	起始行  终止行   起始列  终止列  根据这一列排序   按升序还是降序 
*/ 


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void _sort(vector<vector<int>>& input, vector<int>& change) {
      int raw = change[1] - change[0] + 1;
      int col = change[3] - change[2] + 1;
      
      int s = change[4] - 1;
      vector<pair<int, int>> hashmap(raw);
      int size = 0;
      for (int i = change[0] - 1; i < change[1]; i++) {
            hashmap[size].first = input[i][s];
            hashmap[size].second = i;
            size++;
      }
      //升序
      if (change[5] == 0) {
            for (int i = 0; i < hashmap.size()-1; i++) {
                  for (int j = i+1; j < hashmap.size(); j++) {
                        if (hashmap[i].first > hashmap[j].first) {
                              pair<int, int> temp = hashmap[i];
                              hashmap[i] = hashmap[j];
                              hashmap[j] = temp;
                        }
                  }
            }
      }
      else {
            for (int i = 0; i < hashmap.size() - 1; i++) {
                  for (int j = i + 1; j < hashmap.size(); j++) {
                        if (hashmap[i].first < hashmap[j].first) {
                              pair<int, int> temp = hashmap[i];
                              hashmap[i] = hashmap[j];
                              hashmap[j] = temp;
                        }
                  }
            }
      }

      vector<vector<int>> tmp;
      for (int i = 0; i < hashmap.size(); i++) {
            vector<int> temp;
            for (int j = change[2] - 1; j < change[3]; j++) {
                  temp.push_back(input[hashmap[i].second][j]);
            }
            tmp.push_back(temp);
      }
      int pos1 = 0;
      for (int i = change[0] - 1; i < change[1]; i++) {
            int pos2 = 0;
            for (int j = change[2] - 1; j < change[3]; j++) {
                  input[i][j] = tmp[pos1][pos2++];
            }
            pos1++;
      }
}

int main() {
      int N, M,T;
      cin >> N >> M >> T;
      vector<vector<int>> input(N, vector<int>(M, 0));
      vector<vector<int>> change(T, vector<int>(6, 0));
      for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                  cin >> input[i][j];
            }
      }
      for (int i = 0; i < T; i++) {
            cin >> change[i][0] >> change[i][1] >> change[i][2]
                  >> change[i][3] >> change[i][4] >> change[i][5];
      }
      for (int i = 0; i < T; i++) {
            _sort(input, change[i]);
      }
      for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[0].size(); j++) {
                  cout << input[i][j] << ' ';
            }
            cout << endl;
      }
}
