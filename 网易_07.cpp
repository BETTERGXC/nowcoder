/*
	��һ�������У���һ���ˣ�������Ұ�� 2*R+1
	���������л��м�������������������ƶ������������ţ��ƶ���ʱ���ڵڼ��룩���ƶ��˼�������
	����Ҫ��ѯ����
	ÿ�β�ѯ�ڵڼ���
	���ÿ�β�ѯ��ѯ����Ұ��Χ���м������� 

*/ 


#include <iostream>
#include <vector>
using namespace std;
int main() {
      int M, N, X, Y, R;
      cin >> M >> N >> X >> Y >> R;
      int K;
      cin >> K;
      vector<pair<int, int>> player;
      for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            pair<int, int> tmp;
            tmp.first = x;
            tmp.second = y;
            player.push_back(tmp);
      }
      int c;
      cin >> c;
      vector<vector<int>> move(c, vector<int>(3, 0));
      vector<char> dir(c);
      for (int i = 0; i < c; i++) {
            for (int j = 0; j < 3; j++) {
                  cin >> move[i][j];
            }
            cin >> dir[i];
      }
      int d;
      cin >> d;
      int maxSecond = 0;
      vector<int> find(d);
      for (int i = 0; i < d; i++) {
            cin >> find[i];
            if (find[i] > maxSecond) {
                  maxSecond = find[i];
            }
      }
      vector<int> res;
      for (int m = 0; m <= maxSecond; m++) {
            for (int i = 0; i < move.size(); i++) {
                  if (move[i][1] == m) {
                        if (dir[i] == 'W') {
                              player[move[i][0] - 1].second += move[i][2];
                              if (player[move[i][0] - 1].second > N) {
                                    player[move[i][0] - 1].second = N;
                              }
                        }
                        else if (dir[i] == 'A') {
                              player[move[i][0] - 1].first -= move[i][2];
                              if (player[move[i][0] - 1].first < 0) {
                                    player[move[i][0] - 1].first = 0;
                              }
                        }
                        else if (dir[i] == 'S') {
                              player[move[i][0] - 1].second -= move[i][2];
                              if (player[move[i][0] - 1].second < 0) {
                                    player[move[i][0] - 1].second = 0;
                              }
                        }
                        else if (dir[i] == 'D') {
                              player[move[i][0] - 1].first += move[i][2];
                              if (player[move[i][0] - 1].first > M) {
                                    player[move[i][0] - 1].first = M;
                              }
                        }
                  }
            }
            int count = 0;
            for (int i = 0; i < player.size(); i++) {
                  if (player[i].first <= X + R && player[i].first >= X - R && player[i].second >= Y - R && player[i].second <= Y + R) {
                        count++;
                  }
            }
            res.push_back(count);
      }
      for (int i = 0; i < d; i++) {
            cout << res[find[i]] << " ";
      }
      cout << endl;
}
