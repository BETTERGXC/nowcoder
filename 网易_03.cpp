/*
	输入几个字符串。例如
	A wo
	B go to school
	C chaoxing
	D C A THEN B
	
	问修改一个其中一个字符  会改变几个字符串 
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
      int N;
      cin >> N;
      vector<string> input(N+1);
      for (int i = 0; i <= N; i++) {
            getline(cin, input[i]);
      }
      int M;
      cin >> M;
      vector<string> change(M);
      for (int i = 0; i < M; i++) {
            cin >> change[i];
      }
      unordered_map<string, int> hash;
      for (int i = 0; i < M; i++) {
            hash[change[i]] = 0;
      }
      for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                  auto it = input[i].find(change[j]);
                  if (it != string::npos) {
                        hash[change[j]]++;
                  }
            }
      }
      for (int i = 0; i < M; i++) {
            cout << hash[change[i]] << endl;
      }
}
